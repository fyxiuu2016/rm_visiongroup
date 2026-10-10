#include <memory>
#include <string>
#include <thread>

#include <cv_bridge/cv_bridge.h>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>

#include "frame_source.hpp"
#include "video_file_source.hpp"
#ifdef HAS_MVS_SDK
#include "hik_sdk_source.hpp"
#endif

namespace hik_camera
{

// 海康取图节点：从取图源读帧，原样发布到 /image_raw
// 取图跑在独立线程里（SDK 取帧是阻塞调用），不占用 rclcpp 回调线程
class HikCameraNode : public rclcpp::Node
{
public:
  HikCameraNode() : Node("hik_camera_node")
  {
    // 参数声明（默认值与 config/hik_camera.yaml 保持一致）
    auto mode = declare_parameter<std::string>("mode", "video");
    frame_id_ = declare_parameter<std::string>("frame_id", "camera");

    if (mode == "video") {
      auto path = declare_parameter<std::string>(
        "video_path", "/home/fyxiuu/rm_visiongroup/assets/demo/demo.avi");
      auto loop = declare_parameter<bool>("loop", true);
      source_ = std::make_unique<VideoFileSource>(path, loop);
      RCLCPP_INFO(get_logger(), "视频文件模式: %s (loop=%d)", path.c_str(), loop);
    } else if (mode == "sdk") {
#ifdef HAS_MVS_SDK
      auto exposure_ms = declare_parameter<double>("exposure_ms", 3.0);
      auto gain = declare_parameter<double>("gain", 12.0);
      auto frame_rate = declare_parameter<double>("frame_rate", 150.0);
      source_ = std::make_unique<HikSdkSource>(exposure_ms, gain, frame_rate);
      RCLCPP_INFO(
        get_logger(), "SDK 实机模式: 曝光 %.1fms 增益 %.1fdB 帧率 %.0f",
        exposure_ms, gain, frame_rate);
#else
      throw std::runtime_error("编译时未检测到 MVS SDK，sdk 模式不可用（请改用 video 模式）");
#endif
    } else {
      throw std::runtime_error("未知 mode: " + mode + "（可选 video / sdk）");
    }

    // 图像话题用 SensorDataQoS（允许丢帧、保最新），符合图像流语义
    pub_ = create_publisher<sensor_msgs::msg::Image>("/image_raw", rclcpp::SensorDataQoS());

    worker_ = std::thread(&HikCameraNode::capture_loop, this);
  }

  ~HikCameraNode() override
  {
    running_ = false;
    if (source_) source_->stop();   // 解除 read() 阻塞，让取图线程能退出
    if (worker_.joinable()) worker_.join();
    source_.reset();
  }

private:
  void capture_loop()
  {
    cv::Mat img;
    FrameSource::TimePoint stamp;

    while (running_ && rclcpp::ok()) {
      if (!source_->read(img, stamp)) {
        RCLCPP_INFO(get_logger(), "取图源已结束，节点退出");
        rclcpp::shutdown();
        break;
      }

      // cv_bridge 打包发布；时间戳用节点时钟，下游按 ROS 时间对齐
      auto msg = cv_bridge::CvImage(
        std_msgs::msg::Header(), "bgr8", img).toImageMsg();
      msg->header.stamp = now();
      msg->header.frame_id = frame_id_;
      pub_->publish(*msg);

      // 每 5s 打一次实际发布帧率（WSL 下 ros2 topic hz 受回环传输影响测不准，以节点内统计为准）
      frame_count_++;
      auto elapsed = std::chrono::steady_clock::now() - fps_window_start_;
      if (elapsed >= std::chrono::seconds(5)) {
        RCLCPP_INFO(
          get_logger(), "发布帧率: %.1f fps",
          frame_count_ / std::chrono::duration<double>(elapsed).count());
        frame_count_ = 0;
        fps_window_start_ = std::chrono::steady_clock::now();
      }
    }
  }

  std::unique_ptr<FrameSource> source_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr pub_;
  std::string frame_id_;
  std::thread worker_;
  std::atomic<bool> running_{true};

  // 发布帧率统计（每 5s 一个窗口）
  int frame_count_ = 0;
  std::chrono::steady_clock::time_point fps_window_start_ = std::chrono::steady_clock::now();
};

}  // namespace hik_camera

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  try {
    rclcpp::spin(std::make_shared<hik_camera::HikCameraNode>());
  } catch (const std::exception & e) {
    RCLCPP_FATAL(rclcpp::get_logger("hik_camera"), "节点启动失败: %s", e.what());
  }
  rclcpp::shutdown();
  return 0;
}
