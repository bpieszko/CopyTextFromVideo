#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Video.hpp"
#include "CMDParser.hpp"
#include "OCR.hpp"

int main (int argc, char ** argv)
{
    try
    {
        CMDParser args(argc, argv);
    }
    catch (CMDParserException & e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    auto ocr = OCR::initialize("eng");

    try
    {
        Video video(cv::VideoCapture(args.at("FILE PATH")), ocr);
    }
    catch (Exception & e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    auto video_text = video.getText();

    for (auto i : video_text)
        std::cout << i << std::endl;

    return 0;
}