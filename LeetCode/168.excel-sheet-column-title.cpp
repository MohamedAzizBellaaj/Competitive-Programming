/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string out;
        while (columnNumber > 0)
        {
            char offset = (columnNumber - 1) % 26;
            out = char('A' + offset) + out;
            columnNumber = (columnNumber - 1) / 26;
        }
        return out;
    }
};
// @lc code=end
