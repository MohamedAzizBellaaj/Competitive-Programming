#
# @lc app=leetcode id=70 lang=python3
#
# [70] Climbing Stairs
#


# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1
        prev, curr = 1, 1

        for _ in range(2, n + 1):
            temp = curr
            curr = prev + curr
            prev = temp

        return curr


# @lc code=end
