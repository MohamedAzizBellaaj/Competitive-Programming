#
# @lc app=leetcode id=647 lang=python3
#
# [647] Palindromic Substrings
#


# @lc code=start
class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]

        result = 0
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                dp[i][j] = s[i] == s[j] and ((j - i + 1) < 3 or dp[i + 1][j - 1])
                result += dp[i][j]

        return result


# @lc code=end
