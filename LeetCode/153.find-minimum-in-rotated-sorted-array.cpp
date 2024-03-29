/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1, middle;
        while (left < right)
        {
            middle = left + (right - left) / 2;
            if (nums[middle] > nums[right])
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }
        return nums[left];
    }
};
// @lc code=end
