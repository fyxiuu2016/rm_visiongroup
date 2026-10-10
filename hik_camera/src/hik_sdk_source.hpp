#ifndef HIK_CAMERA__HIK_SDK_SOURCE_HPP_
#define HIK_CAMERA__HIK_SDK_SOURCE_HPP_

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <thread>

#include "frame_source.hpp"

namespace hik_camera
{

// 海康 MVS SDK 实机取图（仅定义了 HAS_MVS_SDK 时编译，见 CMakeLists.txt）
// 结构：后台取流线程把帧放进"最新一帧"槽位，read() 阻塞等新帧
// 取流出错时自动断开并按固定间隔尝试重连
class HikSdkSource : public FrameSource
{
public:
  // exposure_ms: 曝光（毫秒）；gain: 增益（dB）；frame_rate: 帧率上限
  HikSdkSource(double exposure_ms, double gain, double frame_rate);
  ~HikSdkSource() override;

  bool read(cv::Mat & img, TimePoint & stamp) override;

  // 置退出标志并唤醒 read() 里的条件变量等待
  void stop() override
  {
    quit_ = true;
    slot_cv_.notify_all();
  }

private:
  // 打开设备、设置参数、启动取流，返回是否成功
  bool open_device();
  // 停止取流并释放设备句柄
  void close_device();
  // 取流线程主循环：取帧 → 转 BGR → 放入槽位并通知
  void grab_loop();

  double exposure_us_;  // SDK 接口以微秒为单位
  double gain_;
  double frame_rate_;

  void * handle_{nullptr};       // MVS 设备句柄
  std::atomic<bool> quit_{false};       // 析构时通知线程退出
  std::atomic<bool> grabbing_{false};   // 当前是否处于正常取流状态
  std::thread grab_thread_;

  // "最新一帧"槽位：只保留最新帧，旧帧直接丢弃（自瞄只要最新的）
  std::mutex slot_mutex_;
  std::condition_variable slot_cv_;
  cv::Mat latest_img_;
  TimePoint latest_stamp_;
  bool has_new_frame_{false};
};

}  // namespace hik_camera

#endif  // HIK_CAMERA__HIK_SDK_SOURCE_HPP_
