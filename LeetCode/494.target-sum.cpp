/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution
{
public:
    int dfs(vector<int> &nums, int target, int i, vector<unordered_map<int, int>> &mem)
    {
        if (i == nums.size())
        {
            return target == 0;
        }
        auto it = mem[i].find(target);
        if (it != mem[i].end())
        {
            return it->second;
        }
        mem[i][target] = dfs(nums, target + nums[i], i + 1, mem) + dfs(nums, target - nums[i], i + 1, mem);
        return mem[i][target];
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        vector<unordered_map<int, int>> mem(nums.size());
        return dfs(nums, target, 0, mem);
    }
};

// @lc code=end
