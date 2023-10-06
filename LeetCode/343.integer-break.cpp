/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution
{
public:
    int integerBreak(int n)
    {
        if (n <= 3)
        {
            return n - 1;
        }
        switch (n % 3)
        {
        case 0:
            return pow(3, n / 3);
        case 1:
            return pow(3, n / 3 - 1) * 4;
        case 2:
            return pow(3, n / 3) * 2;
        default:
            return -1;
        }
    }
};
// @lc code=end
