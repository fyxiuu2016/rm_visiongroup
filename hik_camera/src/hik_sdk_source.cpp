#include "hik_sdk_source.hpp"

#ifdef HAS_MVS_SDK

#include <MvCameraControl.h>
#include <opencv2/imgproc.hpp>
#include <unordered_map>

#include <rclcpp/rclcpp.hpp>

using namespace std::chrono_literals;

namespace hik_camera
{

namespace
{
// 日志直接用节点同名 logger，保持输出统一
rclcpp::Logger g_logger = rclcpp::get_logger("hik_camera");

// 相机原生 Bayer 格式 → OpenCV 去马赛克方式
const std::unordered_map<MvGvspPixelType, cv::ColorConversionCodes> BAYER_TO_BGR = {
  {PixelType_Gvsp_BayerGR8, cv::COLOR_BayerGR2BGR},
  {PixelType_Gvsp_BayerRG8, cv::COLOR_BayerRG2BGR},
  {PixelType_Gvsp_BayerGB8, cv::COLOR_BayerGB2BGR},
  {PixelType_Gvsp_BayerBG8, cv::COLOR_BayerBG2BGR}};

// SDK 调用结果检查，失败时打一行告警
bool mv_ok(unsigned int ret, const char * what)
{
  if (ret == MV_OK) return true;
  RCLCPP_WARN(g_logger, "%s 失败: 0x%x", what, ret);
  return false;
}
}  // namespace

HikSdkSource::HikSdkSource(double exposure_ms, double gain, double frame_rate)
: exposure_us_(exposure_ms * 1e3), gain_(gain), frame_rate_(frame_rate)
{
  if (!open_device()) {
    throw std::runtime_error("未找到海康相机或打开失败");
  }
  grabbing_ = true;
  grab_thread_ = std::thread(&HikSdkSource::grab_loop, this);
}

HikSdkSource::~HikSdkSource()
{
  quit_ = true;
  slot_cv_.notify_all();   // 唤醒可能阻塞在 read() 的线程
  if (grab_thread_.joinable()) grab_thread_.join();
  close_device();
}

bool HikSdkSource::open_device()
{
  MV_CC_DEVICE_INFO_LIST device_list;
  if (!mv_ok(MV_CC_EnumDevices(MV_USB_DEVICE, &device_list), "枚举相机设备")) return false;
  if (device_list.nDeviceNum == 0) {
    RCLCPP_WARN(g_logger, "未检测到海康相机（USB）");
    return false;
  }

  if (!mv_ok(MV_CC_CreateHandle(&handle_, device_list.pDeviceInfo[0]), "创建句柄")) return false;
  if (!mv_ok(MV_CC_OpenDevice(handle_), "打开设备")) return false;

  // 手动曝光/增益，白平衡连续自动；参数来自 config yaml
  MV_CC_SetEnumValue(handle_, "ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);
  MV_CC_SetEnumValue(handle_, "GainAuto", MV_GAIN_MODE_OFF);
  MV_CC_SetEnumValue(handle_, "BalanceWhiteAuto", MV_BALANCEWHITE_AUTO_CONTINUOUS);
  MV_CC_SetFloatValue(handle_, "ExposureTime", exposure_us_);
  MV_CC_SetFloatValue(handle_, "Gain", gain_);
  MV_CC_SetFrameRate(handle_, frame_rate_);

  return mv_ok(MV_CC_StartGrabbing(handle_), "启动取流");
}

void HikSdkSource::close_device()
{
  if (!handle_) return;
  MV_CC_StopGrabbing(handle_);
  MV_CC_CloseDevice(handle_);
  MV_CC_DestroyHandle(handle_);
  handle_ = nullptr;
}

void HikSdkSource::grab_loop()
{
  MV_FRAME_OUT raw;

  while (!quit_) {
    // 断连状态：每隔 2s 尝试重连，直到成功或退出
    if (!grabbing_) {
      std::this_thread::sleep_for(2s);
      if (quit_) break;
      RCLCPP_INFO(g_logger, "尝试重连相机...");
      if (open_device()) {
        grabbing_ = true;
        RCLCPP_INFO(g_logger, "相机重连成功");
      }
      continue;
    }

    // 阻塞最多 100ms 等一帧
    if (MV_CC_GetImageBuffer(handle_, &raw, 100) != MV_OK) {
      RCLCPP_WARN(g_logger, "取帧失败，相机可能已断开");
      grabbing_ = false;
      close_device();
      continue;
    }

    auto stamp = std::chrono::steady_clock::now();

    // Bayer 原始图 → BGR；不支持 BGR8 直接输出的机型都走这条路
    cv::Mat bgr;
    auto it = BAYER_TO_BGR.find(raw.stFrameInfo.enPixelType);
    if (it != BAYER_TO_BGR.end()) {
      cv::Mat bayer(
        raw.stFrameInfo.nHeight, raw.stFrameInfo.nWidth, CV_8UC1, raw.pBufAddr);
      cv::cvtColor(bayer, bgr, it->second);
    } else {
      RCLCPP_WARN(g_logger, "不支持的像素格式: 0x%lx", raw.stFrameInfo.enPixelType);
      MV_CC_FreeImageBuffer(handle_, &raw);
      continue;
    }
    MV_CC_FreeImageBuffer(handle_, &raw);

    // 放入"最新一帧"槽位并唤醒 read()
    {
      std::lock_guard<std::mutex> lock(slot_mutex_);
      latest_img_ = bgr;
      latest_stamp_ = stamp;
      has_new_frame_ = true;
    }
    slot_cv_.notify_one();
  }
}

bool HikSdkSource::read(cv::Mat & img, TimePoint & stamp)
{
  std::unique_lock<std::mutex> lock(slot_mutex_);
  // 等到有新帧或退出信号
  slot_cv_.wait(lock, [this] { return has_new_frame_ || quit_; });
  if (quit_) return false;

  img = latest_img_;
  stamp = latest_stamp_;
  has_new_frame_ = false;
  return true;
}

}  // namespace hik_camera

#endif  // HAS_MVS_SDK
