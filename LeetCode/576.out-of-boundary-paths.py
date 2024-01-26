#
# @lc app=leetcode id=576 lang=python3
#
# [576] Out of Boundary Paths
#


# @lc code=start
class Solution:
    def findPaths(
        self, m: int, n: int, maxMove: int, startRow: int, startColumn: int
    ) -> int:
        MOD = 10**9 + 7
        dp = [[[-1] * (maxMove + 1) for _ in range(n + 1)] for _ in range(m + 1)]

        def dfs(i, j, maxMove):
            if maxMove < 0:
                return 0
            if i < 0 or i >= m or j < 0 or j >= n:
                return 1

            if dp[i][j][maxMove] != -1:
                return dp[i][j][maxMove]

            a = dfs(i - 1, j, maxMove - 1)
            b = dfs(i + 1, j, maxMove - 1)
            c = dfs(i, j - 1, maxMove - 1)
            d = dfs(i, j + 1, maxMove - 1)

            dp[i][j][maxMove] = a + b + c + d
            return dp[i][j][maxMove]

        return dfs(startRow, startColumn, maxMove) % MOD


# @lc code=end
