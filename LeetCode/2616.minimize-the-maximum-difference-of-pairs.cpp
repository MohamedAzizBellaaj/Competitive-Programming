/*
 * @lc app=leetcode id=2616 lang=cpp
 *
 * [2616] Minimize the Maximum Difference of Pairs
 */

// @lc code=start
class Solution
{
private:
    bool helper(vector<int> &nums, int p, int target)
    {
        int i = 0, n = nums.size();
        while (p > 0 and i < n - 1)
        {
            if (nums[i + 1] - nums[i] <= target)
            {
                p--;
                i++;
            }
            i++;
        }
        return p == 0;
    }

public:
    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = 1e9, middle;
        while (left < right)
        {
            middle = left + (right - left) / 2;
            if (helper(nums, p, middle))
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
