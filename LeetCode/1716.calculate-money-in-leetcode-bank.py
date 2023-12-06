#
# @lc app=leetcode id=1716 lang=python3
#
# [1716] Calculate Money in Leetcode Bank
#


# @lc code=start
class Solution:
    def arithmetic_sum(self, n, f, l):
        return (f + l) * n // 2

    def totalMoney(self, n: int) -> int:
        result = 0
        k = n // 7
        f = 28
        l = 28 + (k - 1) * 7

        result += self.arithmetic_sum(k, f, l)

        result += self.arithmetic_sum(n % 7, 1 + n // 7, 1 + n // 7 + n % 7 - 1)

        return result


# @lc code=end
