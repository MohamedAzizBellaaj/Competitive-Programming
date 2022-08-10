/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        partial_sum(begin(nums), end(nums),begin(nums));
        return nums;
    }
};
// @lc code=end
