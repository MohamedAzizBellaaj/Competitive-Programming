/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
        int cur = INT_MIN, out = 0;
        for (const vector<int> &pair : pairs)
        {
            if (cur < pair[0])
            {
                cur = pair[1];
                out++;
            }
        }
        return out;
    }
};
// @lc code=end
