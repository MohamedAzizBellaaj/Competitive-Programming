/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution
{
private:
    int dp[21][21][2];
    int helper(vector<int> &nums, int i, int j, int turn)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[i][j][turn] != -1)
        {
            return dp[i][j][turn];
        }
        if (turn == 0)
        {
            return dp[i][j][turn] = max(nums[i] + helper(nums, i + 1, j, 1), nums[j] + helper(nums, i, j - 1, 1));
        }
        else
        {
            return dp[i][j][turn] = min(helper(nums, i + 1, j, 0), helper(nums, i, j - 1, 0));
        }
    }

public:
    bool PredictTheWinner(vector<int> &nums)
    {
        int total = 0;
        memset(dp, -1, sizeof(dp));
        for (int x : nums)
        {
            total += x;
        }
        int one = helper(nums, 0, nums.size() - 1, 0);
        return one >= (total - one);
    }
};
// @lc code=end
