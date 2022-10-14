/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0 || x == 1)
        {
            return x;
        }
        if (n == 0)
        {
            return 1;
        }
        else
        {
            double temp = myPow(x, n / 2);
            if (n % 2 == 0)
            {
                return temp * temp;
            }
            else
            {
                if (n > 0)
                {
                    return x * temp * temp;
                }
                else
                {
                    return (temp * temp) / x;
                }
            }
        }
    }
};
// @lc code=end
