/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
 */

// @lc code=start
class Solution
{
private:
    bool check(int x, vector<int> &nums, int k)
    {
        int j = 1, total = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            while (j < nums.size() && nums[j] - nums[i] <= x)
            {
                j++;
            }
            total += j - i - 1;
        }
        return total >= k;
    }

public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front(), middle;
        while (left < right)
        {
            middle = left + (right - left) / 2;
            if (check(middle, nums, k))
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
