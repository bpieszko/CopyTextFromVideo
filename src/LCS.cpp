#include <vector>

#include "LCS.hpp"

namespace LCS {

namespace {

unsigned getSimilarity(const std::string& lhs, const std::string& rhs)
{
    std::vector<std::vector<unsigned>> dp(
        lhs.size() + 1,
        std::vector<unsigned>(rhs.size() + 1, 0));

    for (int i = 0; i <= lhs.size(); ++i)
    {
        for (int j = 0; j <= rhs.size(); ++j)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (lhs[i - 1] == rhs[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[lhs.size()][rhs.size()];
}

}  // namespace

unsigned getSimilarityInPercent(const std::string& lhs, const std::string& rhs)
{
    return getSimilarity(lhs, rhs) * 100 / std::max(lhs.size(), rhs.size());
}

}  // namespace LCS