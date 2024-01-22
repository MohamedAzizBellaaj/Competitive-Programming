#
# @lc app=leetcode id=645 lang=python3
#
# [645] Set Mismatch
#


# @lc code=start
class Solution:
    def findErrorNums(self, A):
        n = len(A)
        count = [0] * (n + 1)

        for x in A:
            count[x] += 1

        for x in range(1, len(A) + 1):
            if count[x] == 2:
                twice = x
            if count[x] == 0:
                never = x

        return twice, never


# @lc code=end
