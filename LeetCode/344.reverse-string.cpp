/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution
{
public:
    void reverseString(vector<char> &s, int i = 0)
    {
        if (i == s.size() / 2)
        {
            return;
        }
        swap(s[i], s[s.size() - 1 - i]);
        reverseString(s, i + 1);
    }
};
// @lc code=end
