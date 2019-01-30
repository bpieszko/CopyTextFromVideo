#include "Video.hpp"

Video::Video(const std::string & file_path)
    : m_video(file_path)
{
    m_text.resize(std::thread::hardware_concurrency());
    if (!m_video.isOpened())
        throw Exception("File path " + file_path + " is incorrect.");
}

std::vector<std::string> Video::getText()
{
    cv::Mat frame;
    std::string frame_text;

    for (int frame_cnt = 0; m_video.isOpened(); ++frame_cnt)
    {
        m_video >> frame;
        
        if (frame.empty())
            break;

        m_frames.push_back(frame.clone());
    }

    m_threads.resize(std::thread::hardware_concurrency());
    const size_t block_size = (size_t)((m_frames.size() + m_threads.size() - 1) / m_threads.size());

    size_t id = 0;
    size_t block_counter = 0;
    for (auto & i : m_threads)
    {
        i = std::thread(&Video::getTextThread, this, block_counter, block_counter + block_size - 1, id++);
        block_counter += block_size;
    }

    for (auto & i : m_threads)
    {
        if (i.joinable())
            i.join();
        else
            throw Exception("Cannot join one of threads.");
    }

    std::vector<std::string> out, result;
    for (auto i : m_text)
        for (auto j : i)
            out.push_back(j + "\n");
    
    result.push_back(out.at(0));
    for (int i = 1; i < out.size(); ++i)
    {
        if (SIMILARITY_PERCENT > LCS::getPercentSimilarity(out.at(i - 1), out.at(i)))
        {
            result.push_back(out[i]);
        }
    }

    return result;
}

void Video::getTextThread(const size_t start, const size_t end, const size_t id)
{
    OCR api(LANGUAGE);

    std::string frame_text;
    std::string last_text;

    for (int frame_cnt = start + (CAPTURE_PER_FRAME - start % CAPTURE_PER_FRAME); frame_cnt <= end; frame_cnt += CAPTURE_PER_FRAME)
    {
        frame_text = api.getText(m_frames[frame_cnt]);

        try 
        {
            last_text = getLastCapturedText(id);

            if (SIMILARITY_PERCENT > LCS::getPercentSimilarity(last_text, frame_text))
            {
                std::lock_guard<std::mutex> lock(m_text_mutex);
                m_text.at(id).push_back(frame_text);
            }
        }
        catch (std::out_of_range & e)
        {
            std::lock_guard<std::mutex> lock(m_text_mutex);
            m_text.at(id).push_back(frame_text);
        }
    }
}

std::string Video::getLastCapturedText(const size_t id)
{
    std::lock_guard<std::mutex> lock(m_text_mutex);
    return m_text.at(id).at(m_text.at(id).size() - 1);
}