#ifndef HIK_CAMERA__FRAME_SOURCE_HPP_
#define HIK_CAMERA__FRAME_SOURCE_HPP_

#include <chrono>
#include <opencv2/core/mat.hpp>

namespace hik_camera
{

// 取图源抽象接口：视频文件、SDK 相机都实现这个接口
// 节点只依赖它，不关心底层是哪种来源
class FrameSource
{
public:
  using TimePoint = std::chrono::steady_clock::time_point;

  virtual ~FrameSource() = default;

  // 阻塞取一帧：img 输出 BGR 图像，stamp 输出取帧时刻
  // 返回 false 表示源已结束且不再产出（如视频播完且不循环、收到 stop）
  virtual bool read(cv::Mat & img, TimePoint & stamp) = 0;

  // 解除 read() 的阻塞并让其尽快返回 false，供节点析构时停止取图线程
  // 默认空实现：适用于 read() 本身有界等待的源（如视频模式，最多等一帧间隔）
  virtual void stop() {}
};

}  // namespace hik_camera

#endif  // HIK_CAMERA__FRAME_SOURCE_HPP_
