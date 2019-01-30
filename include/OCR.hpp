#pragma once

#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <memory>
#include <opencv2/core/mat.hpp>

class OCR
{
public:
    OCR(const std::string & language);
    std::string getText(const cv::Mat & frame);

private:
    std::unique_ptr<tesseract::TessBaseAPI> m_api;
};