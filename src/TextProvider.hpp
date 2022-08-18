#pragma once

#include <thread>

#include "FrameProvider.hpp"
#include "OpticalCharacterRecognition.hpp"

using FrameText = std::pair<FrameId, std::string>;
using FrameTexts = std::vector<FrameText>;

class TextProvider
{
public:
    explicit TextProvider(std::shared_ptr<FrameProvider> frameProviderPtr,
                          std::string language,
                          size_t m_numberOfThreads);

    std::string getText();

private:
    FrameTexts getFrameTexts();

private:
    std::shared_ptr<FrameProvider> m_frameProviderPtr;
    std::string m_language;
    size_t m_numberOfThreads;
    std::vector<std::thread> m_threads;
    FrameTexts m_frameTexts;
};