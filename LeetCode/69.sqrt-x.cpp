/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        unsigned long long left = 0, right = x, middle;
        while (left <= right)
        {
            middle = (left + right) / 2;
            if (middle * middle < x)
            {
                left = middle + 1;
            }
            else if (middle * middle > x)
            {
                right = middle - 1;
            }
            else
            {
                return middle;
            }
        }
        return right;
    }
};
// @lc code=end
