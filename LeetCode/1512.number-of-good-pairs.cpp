/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        int out = 0;
        unordered_map<int, int> m;
        for (const int &num : nums)
        {
            m[num]++;
        }
        for (const auto [num, freq] : m)
        {
            out += (freq * (freq - 1)) / 2;
        }
        return out;
    }
};
// @lc code=end
