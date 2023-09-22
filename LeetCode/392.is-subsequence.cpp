/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0, j = 0;
        while (i < s.size() and j < t.size())
        {
            if (s[i] == t[j])
            {
                i++;
            }
            j++;
        }
        return i == s.size();
    }
};
// @lc code=end
