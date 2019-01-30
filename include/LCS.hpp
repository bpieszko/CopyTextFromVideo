#pragma once

#include <string>
#include <vector>

/*
 * @Brief:
 *      Class responsible for implementing
 *      Longest Common Substring algorithm
 *      to calculate similarity of two
 *      strings expressed in percent value.
 */
class LCS 
{
public:
    LCS() = delete;
    static const int getPercentSimilarity(const std::string & a, const std::string & b);

private:
    static const int getSimilarity(const std::string & a, const std::string & b);
};