/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution
{
private:
    string helper(string &s)
    {
        int i = 0;
        for (const char &c : s)
        {
            if (c != '#')
            {
                s[i] = c;
                i++;
            }
            else if (i > 0)
            {
                i--;
            }
        }
        return s.substr(0, i);
    }

public:
    bool backspaceCompare(string s, string t)
    {
        return helper(s) == helper(t);
    }
};
// @lc code=end
