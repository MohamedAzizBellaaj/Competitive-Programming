/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */

// @lc code=start
class Solution
{
private:
    unordered_map<int, unordered_map<int, double>> dp;
    double helper(int a, int b)
    {
        return 0.25 * (dp[max(0, a - 4)][b] + dp[max(0, a - 3)][b - 1] + dp[max(0, a - 2)][max(0, b - 2)] + dp[a - 1][max(0, b - 3)]);
    }

public:
    double soupServings(int n)
    {
        int m = ceil(n / 25.0);
        dp[0][0] = 0.5;
        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = 0;
            dp[0][i] = 1;
            for (int j = 1; j <= i; j++)
            {
                dp[i][j] = helper(i, j);
                dp[j][i] = helper(j, i);
            }
            if (dp[i][i] > 1 - 1e-5)
            {
                return 1;
            }
        }
        return dp[m][m];
    }
};
// @lc code=end
