#include <numeric>
#include <future>

#include "TextProvider.hpp"
#include "LCS.hpp"

namespace {

constexpr unsigned FRAMES_PER_SECOND_OPTIMIZATION{30};

FrameTexts getTextInThread(std::shared_ptr<FrameProvider> frameProviderPtr,
                           const std::string& language)
{
    OpticalCharacterRecognition ocr{language};
    FrameTexts frameTexts;

    unsigned counter{0};
    while (true)
    {
        auto [frame, frameId] = frameProviderPtr->getNextFrame();
        if (frame.empty())
        {
            break;
        }

        ++counter;
        if (counter % FRAMES_PER_SECOND_OPTIMIZATION) continue;

        auto text = ocr.getText(frame);
        if (not text.empty())
        {
            frameTexts.push_back({frameId, text});
        }
    }

    return frameTexts;
}

constexpr unsigned MAX_SIMILARITY = 95;

std::vector<std::string> removeDuplicates(FrameTexts frameTexts)
{
    std::vector<std::string> ret;
    ret.push_back(frameTexts.front().second);
    for (size_t it = 1; it < frameTexts.size(); ++it)
    {
        const auto similarity = 
            LCS::getSimilarityInPercent(ret.back(), frameTexts[it].second);
        if (similarity <= MAX_SIMILARITY)
        {
            ret.emplace_back(std::move(frameTexts[it].second));
        }
    }
    return ret;
}

}  // namespace

TextProvider::TextProvider(std::shared_ptr<FrameProvider> frameProviderPtr,
                           std::string language,
                           size_t numberOfThreads)
: m_frameProviderPtr{frameProviderPtr}
, m_language{std::move(language)}
, m_numberOfThreads{numberOfThreads}
{
}

std::string TextProvider::getText()
{
    auto frameTexts = getFrameTexts();

    std::sort(frameTexts.begin(),
              frameTexts.end(),
              [](const FrameText& lhs, const FrameText& rhs)
              {
                  return lhs.first < rhs.first;
              });

    auto texts = removeDuplicates(std::move(frameTexts));

    return std::accumulate(texts.cbegin(), texts.cend(), std::string{""});
}

FrameTexts TextProvider::getFrameTexts()
{
    std::vector<std::future<FrameTexts>> futures;

    for (size_t threadNr = 0; threadNr < m_numberOfThreads; ++ threadNr)
    {
        futures.emplace_back(std::async(getTextInThread,
                                        m_frameProviderPtr,
                                        m_language));
    }

    std::vector<std::pair<FrameId, std::string>> frameTexts;
    for (auto& future : futures)
    {
        auto frameTextsFromFuture = future.get();
        frameTexts.insert(frameTexts.end(),
                          std::make_move_iterator(frameTextsFromFuture.begin()),
                          std::make_move_iterator(frameTextsFromFuture.end()));
    }

    return frameTexts;
}