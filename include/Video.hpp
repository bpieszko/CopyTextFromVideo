#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <string>
#include <vector>
#include "Exception.hpp"
#include "OCR.hpp"
#include "LCS.hpp"

class Video
{
public:
    Video(const std::string & file_path);

    std::vector<std::string> getText();

private:
    cv::VideoCapture m_video;
    OCR m_api;
    std::vector<std::string> m_text;

    static const size_t CAPTURE_PER_FRAME = 100;
    static const size_t SIMILARITY_PERCENT = 90;
    static const constexpr char * LANGUAGE = "eng";
};