/*
 * @lc app=leetcode id=1793 lang=cpp
 *
 * [1793] Maximum Score of a Good Subarray
 */

// @lc code=start
class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int l = k, r = k, res = nums[k], curMin = nums[k];
        
        while (l > 0 or r < nums.size() - 1)
        {
            int left = l - 1 >= 0 ? nums[l - 1] : 0;
            int right = r + 1 < nums.size() ? nums[r + 1] : 0;
            if (left > right)
            {
                l--;
                curMin = min(curMin, left);
            }
            else
            {
                r++;
                curMin = min(curMin, right);
            }
            res = max(res, curMin * (r - l + 1));
        }

        return res;
    }
};
// @lc code=end
