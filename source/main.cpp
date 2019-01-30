#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Video.hpp"
#include "CMDParser.hpp"
#include "OCR.hpp"

int main (int argc, char ** argv)
{
    std::unique_ptr<CMDParser> args;
    try
    {
        args = std::unique_ptr<CMDParser>(new CMDParser(argc, argv));
    }
    catch (CMDParserException & e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    std::unique_ptr<Video> video;
    try
    {
        video = std::unique_ptr<Video>(new Video(args->at("FILE PATH")));
    }
    catch (Exception & e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    auto video_text = video->getText();

    for (auto i : video_text)
        std::cout << i << std::endl;

    return 0;
}