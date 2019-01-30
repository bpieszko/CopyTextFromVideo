/*
 * Author: Bartosz Pieszko
 * E-Mail: bartosz.pieszko@gmail.com
 * Licence: MIT
 */
#include "Video.hpp"
#include "CMDParser.hpp"

int main (int argc, char ** argv)
{
    std::unique_ptr<CMDParser> args;
    std::unique_ptr<Video> video;
    
    try
    {
        args = std::unique_ptr<CMDParser>(new CMDParser(argc, argv));
        video = std::unique_ptr<Video>(new Video(args->at("-v")));
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