/*
 * @lc app=leetcode id=1930 lang=cpp
 *
 * [1930] Unique Length-3 Palindromic Subsequences
 */

// @lc code=start
class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        vector<int> first = vector(26, -1);
        vector<int> last = vector(26, -1);

        for (int i = 0; i < s.size(); i++)
        {
            int curr = s[i] - 'a';
            if (first[curr] == -1)
            {
                first[curr] = i;
            }

            last[curr] = i;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (first[i] == -1)
            {
                continue;
            }

            unordered_set<char> between;
            for (int j = first[i] + 1; j < last[i]; j++)
            {
                between.insert(s[j]);
            }

            ans += between.size();
        }

        return ans;
    }
};
// @lc code=end
