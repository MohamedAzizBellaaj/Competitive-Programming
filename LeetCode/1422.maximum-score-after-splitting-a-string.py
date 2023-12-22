#
# @lc app=leetcode id=1422 lang=python3
#
# [1422] Maximum Score After Splitting a String
#


# @lc code=start
class Solution:
    def maxScore(self, s: str) -> int:
        ones = 0
        zeros = 0
        best = float("-inf")

        for i in range(len(s) - 1):
            if s[i] == "1":
                ones += 1
            else:
                zeros += 1

            best = max(best, zeros - ones)

        if s[-1] == "1":
            ones += 1

        return best + ones


# @lc code=end
