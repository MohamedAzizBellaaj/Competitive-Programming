/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

// @lc code=start
class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (n == 1 && k == 1)
        {
            return 0;
        }
        else
        {
            int length = pow(2, n - 1);
            if (k <= length / 2)
            {
                return kthGrammar(n - 1, k);
            }
            else
            {
                return !kthGrammar(n - 1, k - length / 2);
            }
        }
    }
};
// @lc code=end
