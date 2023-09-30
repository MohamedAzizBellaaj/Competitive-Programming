/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        stack<pair<int, int>> stack;
        int curMin = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            while (!stack.empty() and nums[i] >= stack.top().first)
            {
                stack.pop();
            }
            if (!stack.empty() and nums[i] > stack.top().second)
            {
                return true;
            }
            stack.push({nums[i], curMin});
            curMin = min(nums[i], curMin);
        }
        return false;
    }
};
// @lc code=end
