/*
 * @lc app=leetcode id=2366 lang=cpp
 *
 * [2366] Minimum Replacements to Sort the Array
 */

// @lc code=start
class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        long long out = 0;
        int n = nums.size(), maxi = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] <= nums[i + 1])
            {
                continue;
            }
            int numElements = ceil(nums[i] / (double)nums[i + 1]);
            out += numElements - 1;
            nums[i] = nums[i] / numElements;
        }
        return out;
    }
};
// @lc code=end
