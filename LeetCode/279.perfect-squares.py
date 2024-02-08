#
# @lc app=leetcode id=279 lang=python3
#
# [279] Perfect Squares
#


# @lc code=start
import math


class Solution:
    def numSquares(self, n: int) -> int:
        choices = [x * x for x in range(1, n + 1) if x <= math.sqrt(n)]
        dp = [n] * (n + 1)
        dp[0] = 0

        for target in range(n + 1):
            for choice in choices:
                if target - choice < 0:
                    break

                dp[target] = min(dp[target], 1 + dp[target - choice])

        return dp[n]


# @lc code=end
