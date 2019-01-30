#include "LCS.hpp"

const int LCS::getPercentSimilarity(const std::string & a, const std::string & b)
{
    return getSimilarity(a, b) * 100 / std::max(a.size(), b.size());
}

const int LCS::getSimilarity(const std::string & a, const std::string & b)
{
    std::vector<std::vector<int>> dp(a.size() + 1, std::vector<int>(b.size() + 1, 0));

    for (int i = 0; i <= a.size(); ++i)
    {
        for (int j = 0; j <= b.size(); ++j)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[a.size()][b.size()];
}