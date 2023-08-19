/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    
    void backtrack(vector<int> &curr, vector<int> &nums)
    {
        if (curr.size() == nums.size())
        {
            result.push_back(curr);
            return;
        }
        for (int num : nums)
        {
            if (find(curr.begin(), curr.end(), num) == curr.end())
            {
                curr.push_back(num);
                backtrack(curr, nums);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> curr;
        backtrack(curr, nums);
        return result;
    }
};
// @lc code=end
