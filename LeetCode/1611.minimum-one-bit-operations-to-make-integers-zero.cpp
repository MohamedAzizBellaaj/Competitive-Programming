/*
 * @lc app=leetcode id=1611 lang=cpp
 *
 * [1611] Minimum One Bit Operations to Make Integers Zero
 */

// @lc code=start
class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        int result = 0;
        int k = 0;
        int mask = 1;

        while (mask <= n)
        {
            if ((n & mask) != 0)
            {
                result = (1 << (k + 1)) - 1 - result;
            }

            mask <<= 1;
            k++;
        }

        return result;
    }
};
// @lc code=end
