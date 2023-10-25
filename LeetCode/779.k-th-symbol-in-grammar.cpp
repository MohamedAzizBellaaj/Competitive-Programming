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
        if (n == 1 and k == 1)
        {
            return 0;
        }
        if (k <= pow(2, n - 1) / 2)
        {
            return kthGrammar(n - 1, k);
        }
        else if (n % 2 == 1)
        {
            return kthGrammar(n - 1, pow(2, n - 1) - k + 1);
        }
        else
        {
            return !kthGrammar(n - 1, pow(2, n - 1) - k + 1);
        }
    }
};
// @lc code=end
