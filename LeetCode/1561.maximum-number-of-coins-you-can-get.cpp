/*
 * @lc app=leetcode id=1561 lang=cpp
 *
 * [1561] Maximum Number of Coins You Can Get
 */

// @lc code=start
class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        int result = 0;
        int n = piles.size();
        sort(piles.begin(), piles.end());

        for (int i = n / 3; i < n; i += 2)
        {
            result += piles[i];
        }

        return result;
    }
};
// @lc code=end
