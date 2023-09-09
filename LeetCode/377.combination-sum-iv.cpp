/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        unsigned int dp[target + 1];
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            dp[i] = 0;
            for (const int &num : nums)
            {
                if (i - num >= 0)
                {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end
