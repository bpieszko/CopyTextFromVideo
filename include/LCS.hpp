#pragma once

#include <string>
#include <vector>

class LCS 
{
public:
    LCS() = delete;
    static const int getPercentSimilarity(const std::string & a, const std::string & b);

private:
    static const int getSimilarity(const std::string & a, const std::string & b);
};