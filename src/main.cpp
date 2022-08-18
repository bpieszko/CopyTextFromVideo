/*
 * Author: Bartosz Pieszko
 * E-Mail: bartosz.pieszko@gmail.com
 * Licence: MIT
 */

#include <iostream>

#include "FrameProvider.hpp"
#include "OpticalCharacterRecognition.hpp"
#include "TextProvider.hpp"

constexpr size_t NUMBER_OF_THREADS{8};
const std::string LANGUAGE{"eng"};

std::string getVideoFileName(const int argc, char* argv[])
{
    if (argc != 2)
    {
        throw std::runtime_error("Incorrect number of arguments");
    }

    return argv[1];
}

cv::VideoCapture getVideo(std::string fileName)
{
    cv::VideoCapture video{std::move(fileName)};
    if (not video.isOpened())
    {
        throw std::runtime_error("Cannot open a file.");
    }
    return video;
}

int main (int argc, char* argv[])
{
    cv::VideoCapture video;

    try
    {
        video = getVideo(getVideoFileName(argc, argv));
    }
    catch (std::runtime_error& exception)
    {
        std::cerr << exception.what() << std::endl;
        return 1;
    }

    if (not video.isOpened())
    {
        std::cerr << "Cannot open video file." << std::endl;
        return 1;
    }

    auto frameProviderPtr = std::make_shared<FrameProvider>(std::move(video));
    TextProvider textProvider{frameProviderPtr, LANGUAGE, NUMBER_OF_THREADS};

    std::cout << textProvider.getText() << std::endl;

    return 0;
}