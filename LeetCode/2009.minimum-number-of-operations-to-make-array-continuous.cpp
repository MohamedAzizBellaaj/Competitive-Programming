/*
 * @lc app=leetcode id=2009 lang=cpp
 *
 * [2009] Minimum Number of Operations to Make Array Continuous
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int length = nums.size();
        int res = length;
        set<int> unique(nums.begin(), nums.end());
        vector<int> newNums(unique.begin(), unique.end());
        int r = 0;
        for (int l = 0; l < newNums.size(); l++)
        {
            while (r < newNums.size() and newNums[r] < newNums[l] + length)
            {
                r++;
            }
            int window = r - l;
            res = min(res, length - window);
        }

        return res;
    }
};
// @lc code=end
