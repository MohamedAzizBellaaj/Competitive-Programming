/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int prev1 = 0, prev2 = 0, res;
        for (int i = 2; i <= cost.size(); i++)
        {
            res = min(cost[i - 1] + prev1, cost[i - 2] + prev2);
            prev2 = prev1;
            prev1 = res;
        }
        return res;
    }
};
// @lc code=end
