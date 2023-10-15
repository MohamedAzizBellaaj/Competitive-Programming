/*
 * @lc app=leetcode id=1269 lang=cpp
 *
 * [1269] Number of Ways to Stay in the Same Place After Some Steps
 */

// @lc code=start
class Solution
{
public:
    int numWays(int steps, int arrLen)
    {
        int mod = 1e9 + 7;
        arrLen = min(arrLen, steps);
        vector<int> dp(arrLen, 0);
        vector<int> prevDp(arrLen, 0);
        prevDp[0] = 1;

        for (int remain = 1; remain <= steps; remain++)
        {
            dp = vector(arrLen, 0);

            for (int curr = arrLen - 1; curr >= 0; curr--)
            {
                int ans = prevDp[curr];

                if (curr > 0)
                {
                    ans = (ans + prevDp[curr - 1]) % mod;
                }

                if (curr < arrLen - 1)
                {
                    ans = (ans + prevDp[curr + 1]) % mod;
                }

                dp[curr] = ans;
            }
            
            prevDp = dp;
        }

        return dp[0];
    }
};
// @lc code=end
