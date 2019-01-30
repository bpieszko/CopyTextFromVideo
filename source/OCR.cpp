#include "OCR.hpp"

OCR::OCR(const std::string & language)
{
    m_api = std::unique_ptr<tesseract::TessBaseAPI>(new tesseract::TessBaseAPI());
    m_api->Init(NULL, language.c_str(), tesseract::OEM_LSTM_ONLY);
    m_api->SetPageSegMode(tesseract::PSM_AUTO);
}

std::string OCR::getText(const cv::Mat & frame)
{
    m_api->SetImage(frame.data, frame.cols, frame.rows, 3, frame.step);
    return m_api->GetUTF8Text();
}