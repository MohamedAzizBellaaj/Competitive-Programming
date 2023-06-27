/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int s = 0, f = 0;
        do
        {
            s = nums[s];
            f = nums[nums[f]];
        } while (f != s);
        s = 0;
        while (f != s)
        {
            s = nums[s];
            f = nums[f];
        }
        return f;
    }
};
// @lc code=end
