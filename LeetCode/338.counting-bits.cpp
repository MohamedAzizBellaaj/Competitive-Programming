/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution
{
public:
    vector<int> countBits(int n)
    {
        if (n == 0)
        {
            return {0};
        }
        vector<int> res(n + 1);
        res[0] = 0;
        res[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            if (i % 2 == 0)
            {
                res[i] = res[i / 2];
            }
            else
            {
                res[i] = res[i / 2] + 1;
            }
        }
        return res;
    }
};
// @lc code=end
