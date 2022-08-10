/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start
class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int maxi = 0, sum;
        for (vector<int> v : accounts)
        {
            sum = accumulate(begin(v), end(v), 0);
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};
// @lc code=end
