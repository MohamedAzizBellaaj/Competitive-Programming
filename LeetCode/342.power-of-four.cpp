/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        float val = log2(n) / 2;
        return (val == (int)val);
    }
};
// @lc code=end
