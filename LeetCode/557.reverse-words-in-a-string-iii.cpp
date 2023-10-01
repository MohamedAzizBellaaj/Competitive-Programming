/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        int i = 0;
        while (i < s.size())
        {
            int j = i;
            while (j < s.size() and s[j] != ' ')
            {
                j++;
            }
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        return s;
    }
};
// @lc code=end
