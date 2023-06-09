/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
private:
    int helper(int i, vector<int> &nums)
    {
        int pivot = min_element(nums.begin(), nums.end()) - nums.begin();
        return (i + pivot) % nums.size();
    }

public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, middle;
        while (left <= right)
        {
            middle = right + (left - right) / 2;
            int pivoted_middle = helper(middle, nums);
            if (nums[pivoted_middle] < target)
            {
                left = middle + 1;
            }
            else if (nums[pivoted_middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                return pivoted_middle;
            }
        }
        return -1;
    }
};
// @lc code=end
