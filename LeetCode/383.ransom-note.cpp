/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> m1, m2;
        for (int i = 0; i < ransomNote.size(); i++)
        {
            m1[ransomNote[i]]++;
        }
        for (int i = 0; i < magazine.size(); i++)
        {
            m2[magazine[i]]++;
        }
        for (auto const &x : m1)
        {
            if (x.second > m2[x.first])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
