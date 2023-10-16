/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res(1, 1);
        unsigned long long prev = 1;
        for (int k = 1; k <= rowIndex; k++)
        {
            unsigned long long next = prev * (rowIndex - k + 1) / k;
            res.push_back(next);
            prev = next;
        }
        return res;
    }
};
// @lc code=end
