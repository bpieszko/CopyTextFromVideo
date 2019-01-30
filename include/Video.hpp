#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include "Exception.hpp"
#include "OCR.hpp"
#include "LCS.hpp"

/*
 * @Brief:
 *      Class responsible for capture text from video.
 */
class Video
{
public:
    Video(const std::string & file_path);

    std::vector<std::string> getText();

private:
    void getTextThread(const size_t start, const size_t end, const size_t id);
    std::string getLastCapturedText(const size_t id);

    cv::VideoCapture m_video;
    std::vector<std::vector<std::string>> m_text;
    std::mutex m_text_mutex;

    std::vector<std::thread> m_threads;
    std::vector<cv::Mat> m_frames;

    static const size_t CAPTURE_PER_FRAME = 100;
    static const size_t SIMILARITY_PERCENT = 90;
    static const constexpr char * LANGUAGE = "eng";
};