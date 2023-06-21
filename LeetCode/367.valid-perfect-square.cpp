/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 1, right = num / 2 + 1, middle;
        while (left <= right)
        {
            middle = left + (right - left) / 2;
            unsigned long long x = (unsigned long long)middle * middle;
            if (x < num)
            {
                left = middle + 1;
            }
            else if (x > num)
            {
                right = middle - 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
