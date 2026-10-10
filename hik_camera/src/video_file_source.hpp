#ifndef HIK_CAMERA__VIDEO_FILE_SOURCE_HPP_
#define HIK_CAMERA__VIDEO_FILE_SOURCE_HPP_

#include <string>
#include <opencv2/videoio.hpp>

#include "frame_source.hpp"

namespace hik_camera
{

// 视频文件取图：按视频自身帧率节拍吐帧，模拟真实相机的发布节奏
// 用于 WSL 等无相机环境下的链路调试
class VideoFileSource : public FrameSource
{
public:
  // path: 视频文件路径；loop: 播完是否回到开头循环
  VideoFileSource(const std::string & path, bool loop);
  ~VideoFileSource() override = default;

  bool read(cv::Mat & img, TimePoint & stamp) override;

private:
  // 打开（或重新打开）视频并复位节拍起点，返回是否成功
  bool reopen();

  cv::VideoCapture cap_;
  std::string path_;
  bool loop_;

  double frame_interval_ms_;  // 相邻两帧的间隔（毫秒），取自视频帧率
  long frame_index_;          // 已吐出的帧计数，用于节拍对齐
  TimePoint start_time_;      // 本次播放的节拍起点
};

}  // namespace hik_camera

#endif  // HIK_CAMERA__VIDEO_FILE_SOURCE_HPP_
