#include "FrameProvider.hpp"

FrameProvider::FrameProvider(cv::VideoCapture video) : m_video{std::move(video)}
{
}
    
std::pair<Frame, FrameId> FrameProvider::getNextFrame()
{
    std::lock_guard guard{m_mutex};

    static size_t frameId{0};

    cv::Mat frame;
    m_video >> frame;
    return {frame, frameId++};
}
