/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        unsigned long long out = 1;
        for (int i = m + n - 2, j = 1; i >= max(m, n); i--, j++)
        {
            out = (out * i) / j;
        }
        return out;
    }
};
// @lc code=end
