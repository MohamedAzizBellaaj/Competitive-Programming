/*
 * @lc app=leetcode id=1458 lang=cpp
 *
 * [1458] Max Dot Product of Two Subsequences
 */

// @lc code=start
class Solution
{
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        int firstMax = *max_element(nums1.begin(), nums1.end());
        int secondMax = *max_element(nums2.begin(), nums2.end());
        int firstMin = *min_element(nums1.begin(), nums1.end());
        int secondMin = *min_element(nums2.begin(), nums2.end());
        if (firstMax < 0 && secondMin > 0)
        {
            return firstMax * secondMin;
        }
        if (firstMin > 0 && secondMax < 0)
        {
            return firstMin * secondMax;
        }

        int m = nums2.size() + 1;
        vector<int> dp(m, 0);
        vector<int> prevDp(m, 0);
        for (int i = nums1.size() - 1; i >= 0; i--)
        {
            dp = vector(m, 0);
            for (int j = nums2.size() - 1; j >= 0; j--)
            {
                int use = nums1[i] * nums2[j] + prevDp[j + 1];
                dp[j] = max(use, max(prevDp[j], dp[j + 1]));
            }

            prevDp = dp;
        }
        return dp[0];
    }
};
// @lc code=end
