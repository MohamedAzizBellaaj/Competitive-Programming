/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1, middle;
        while (left < right)
        {
            middle = left + (right - left) / 2;
            if (middle == nums.size() - 1 || nums[middle] < nums[middle + 1])
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }
        return left;
    }
};
// @lc code=end
