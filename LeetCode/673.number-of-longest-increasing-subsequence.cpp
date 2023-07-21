/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        vector<pair<int, int>> dp(nums.size());
        int largestLISLength = 0, out = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int maxLength = 1, maxCount = 1;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] < nums[j])
                {
                    int length = dp[j].first, count = dp[j].second;
                    if (length + 1 > maxLength)
                    {
                        maxLength = length + 1;
                        maxCount = count;
                    }
                    else if (length + 1 == maxLength)
                    {
                        maxCount += count;
                    }
                }
            }
            if (maxLength > largestLISLength)
            {
                largestLISLength = maxLength;
                out = maxCount;
            }
            else if (maxLength == largestLISLength)
            {
                out += maxCount;
            }
            dp[i] = {maxLength, maxCount};
        }
        return out;
    }
};
// @lc code=end
