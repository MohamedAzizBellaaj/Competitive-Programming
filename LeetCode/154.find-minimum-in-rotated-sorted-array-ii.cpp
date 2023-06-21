/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
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
            else if (nums[middle] < nums[right])
            {
                right = middle;
            }
            else
            {
                right--;
            }
        }
        return nums[left];
    }
};
// @lc code=end
