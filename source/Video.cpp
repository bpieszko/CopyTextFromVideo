#include "Video.hpp"

Video::Video(const std::string & file_path)
    : m_video(file_path), m_api(LANGUAGE)
{
    if (!m_video.isOpened())
        throw VideoException("File path " + file_path + " is incorrect.");
}

std::vector<std::string> & Video::getText()
{
    cv::Mat frame;
    std::string frame_text;
    std::vector<std::string> result_text;

    for (int frame_cnt = 0; m_video.isOpened(); ++frame_cnt)
    {
        m_video >> frame;

        if (frame.empty())
            break;

        if (frame_cnt % CAPTURE_PER_FRAME == 0)
        {
            frame_text = m_api.getText(frame);

            if (result_text.empty() ||
                SIMILARITY_PERCENT < LCS::getPercentSimilarity(result_text.back(), frame_text))
            {
                result_text.push_back(frame_text);
            }
        }
    }
    
    return result_text;
}

VideoException::VideoException(const std::string & message)
    : Exception(message.c_str())
{

}