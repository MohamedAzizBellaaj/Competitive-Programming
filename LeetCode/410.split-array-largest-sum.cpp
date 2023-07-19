/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution
{
private:
    int helper(vector<int> &nums, int k, int middle)
    {
        int acc = 0;
        for (int x : nums)
        {
            acc += x;
            if (acc > middle)
            {
                k--;
                acc = x;
            }
        }
        return k > 0;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        int left = *max_element(nums.begin(), nums.end()), right = accumulate(nums.begin(), nums.end(), 0), middle;
        while (left < right)
        {
            middle = left + (right - left) / 2;
            if (helper(nums, k, middle))
            {
                right = middle;
            }
            else
            {
                left = middle + 1;
            }
        }
        return right;
    }
};
// @lc code=end
