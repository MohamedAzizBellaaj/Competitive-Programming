/*
 * @lc app=leetcode id=1359 lang=cpp
 *
 * [1359] Count All Valid Pickup and Delivery Options
 */

// @lc code=start
class Solution
{
private:
    unsigned int mod = int(1e9) + 7;

public:
    int countOrders(int n)
    {
        unsigned long long out = 1;
        for (int i = 2 * n; i > 0; i -= 2)
        {
            unsigned int validChoices = ((i * (i - 1)) / 2);
            out *= validChoices;
            out %= mod;
        }
        return out;
    }
};
// @lc code=end
