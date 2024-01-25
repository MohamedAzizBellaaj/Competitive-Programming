#
# @lc app=leetcode id=1143 lang=python3
#
# [1143] Longest Common Subsequence
#


# @lc code=start
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # n = max(len(text1), len(text2))
        # memo = [[-1] * n for _ in range(n)]

        # def dfs(i, j):
        #     if i >= len(text1) or j >= len(text2):
        #         return 0

        #     if memo[i][j] != -1:
        #         return memo[i][j]

        #     if text1[i] == text2[j]:
        #         result = 1 + dfs(i + 1, j + 1)

        #     else:
        #         result = max(dfs(i + 1, j), dfs(i, j + 1))

        #     memo[i][j] = result

        #     return result

        # return dfs(0, 0)

        # n = max(len(text1), len(text2))
        # dp = [[0] * (n + 1) for _ in range(n + 1)]

        # for i in range(len(text1) - 1, -1, -1):
        #     for j in range(len(text2) - 1, -1, -1):
        #         if text1[i] == text2[j]:
        #             dp[i][j] = 1 + dp[i + 1][j + 1]
        #         else:
        #             dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])

        # return dp[0][0]

        n = max(len(text1), len(text2))

        m, n = len(text1), len(text2)
        dp = [0] * (n + 1)

        for i in range(m - 1, -1, -1):
            new_dp = [0] * (n + 1)

            for j in range(n - 1, -1, -1):
                if text1[i] == text2[j]:
                    new_dp[j] = 1 + dp[j + 1]

                else:
                    new_dp[j] = max(dp[j], new_dp[j + 1])
            dp = new_dp

        return dp[0]


# @lc code=end
