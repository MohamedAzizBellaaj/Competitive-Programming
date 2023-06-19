/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
private:
    int binarySearch(vector<int> &nums, int target, int leftBias)
    {
        int left = 0, right = nums.size() - 1, middle, index = -1;
        while (left <= right)
        {
            middle = left + (right - left) / 2;
            if (nums[middle] > target)
            {
                right = middle - 1;
            }
            else if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                index = middle;
                if (leftBias)
                {
                    right = middle - 1;
                }
                else
                {
                    left = middle + 1;
                }
            }
        }
        return index;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = binarySearch(nums, target, true), last = binarySearch(nums, target, false);
        return vector<int>{first, last};
    }
};
// @lc code=end
