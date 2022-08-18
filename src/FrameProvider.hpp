#pragma once

#include <opencv2/videoio.hpp>
#include <mutex>

using FrameId = size_t;
using Frame = cv::Mat;

class FrameProvider
{
public:
    explicit FrameProvider(cv::VideoCapture video);
    
    std::pair<Frame, FrameId> getNextFrame();

private:
    cv::VideoCapture m_video;
    std::mutex m_mutex;
};
