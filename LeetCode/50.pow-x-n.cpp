/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, long n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n < 0)
        {
            return 1 / myPow(x, -n);
        }
        double out = myPow(x * x, n / 2);
        if (n % 2 == 1)
        {
            double rest = n < 0 ? 1 / x : x;
            out *= rest;
        }
        return out;
    }
};
// @lc code=end
