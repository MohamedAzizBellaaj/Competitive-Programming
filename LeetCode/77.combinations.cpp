/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;

    void helper(int index, int k, vector<int> &current, int n)
    {
        if (current.size() == k)
        {
            res.push_back(current);
            return;
        }

        for (int i = index; i <= n; i++)
        {
            current.push_back(i);
            helper(i + 1, k, current, n);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> current;
        helper(1, k, current, n);
        return res;
    }
};
// @lc code=end
