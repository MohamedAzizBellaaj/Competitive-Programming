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
        if (nums.size() == 1)
        {
            return nums.front();
        }
        if (nums.front() < nums.back())
        {
            return nums.front();
        }
        int left = 0, right = nums.size() - 1, middle;
        while (left < right)
        {
            middle = left + (right - left) / 2;
            if (nums[middle] > nums[middle + 1])
            {
                return nums[middle + 1];
            }
            if (nums[middle] < nums[middle - 1])
            {
                return nums[middle];
            }
            if (nums[middle] > nums.front())
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }
        if (nums[right] < nums[right - 1])
        {
            return nums[right];
        }
        else
        {
            return nums[right + 1];
        }
    }
};
// @lc code=end
