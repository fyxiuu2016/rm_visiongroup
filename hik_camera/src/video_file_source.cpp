#include "video_file_source.hpp"

#include <thread>

namespace hik_camera
{

VideoFileSource::VideoFileSource(const std::string & path, bool loop)
: path_(path), loop_(loop), frame_index_(0)
{
  if (!reopen()) {
    throw std::runtime_error("无法打开视频文件: " + path);
  }
}

bool VideoFileSource::reopen()
{
  cap_.open(path_);
  if (!cap_.isOpened()) return false;

  // 从视频元数据读帧率，算帧间隔；读不到时兜底 30fps
  double fps = cap_.get(cv::CAP_PROP_FPS);
  if (fps <= 1e-3) fps = 30.0;
  frame_interval_ms_ = 1000.0 / fps;

  // 每次重开都重置节拍，保证循环播放时节奏依然均匀
  frame_index_ = 0;
  start_time_ = std::chrono::steady_clock::now();
  return true;
}

bool VideoFileSource::read(cv::Mat & img, TimePoint & stamp)
{
  while (true) {
    // 节拍对齐：等到"第 N 帧该出现的时刻"再吐帧，模拟相机固定帧率
    auto target = start_time_ +
      std::chrono::duration_cast<TimePoint::duration>(
        std::chrono::duration<double, std::milli>(frame_index_ * frame_interval_ms_));
    std::this_thread::sleep_until(target);

    if (cap_.read(img) && !img.empty()) {
      frame_index_++;
      stamp = std::chrono::steady_clock::now();
      return true;
    }

    // 读到末尾：循环则重开，否则告诉节点源已结束
    if (!loop_) return false;
    if (!reopen()) return false;
  }
}

}  // namespace hik_camera
