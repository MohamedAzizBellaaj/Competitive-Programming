/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 */

// @lc code=start
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int word1Pointer = 0, word2Pointer = 0;
        int string1Pointer = 0, string2Pointer = 0;

        while (word1Pointer < word1.size() && word2Pointer < word2.size())
        {
            if (word1[word1Pointer][string1Pointer++] != word2[word2Pointer][string2Pointer++])
            {
                return false;
            }

            if (string1Pointer == word1[word1Pointer].size())
            {
                word1Pointer++;
                string1Pointer = 0;
            }

            if (string2Pointer == word2[word2Pointer].size())
            {
                word2Pointer++;
                string2Pointer = 0;
            }
        }

        return word1Pointer == word1.size() && word2Pointer == word2.size();
    }
};
// @lc code=end
