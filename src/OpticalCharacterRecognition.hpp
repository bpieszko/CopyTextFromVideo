#pragma once

#include <mutex>
#include <tesseract/baseapi.h>
#include <opencv2/core/mat.hpp>

class OpticalCharacterRecognition
{
public:
    explicit OpticalCharacterRecognition(const std::string& language);
    std::string getText(const cv::Mat& frame);

private:
    tesseract::TessBaseAPI m_api;
};
