#
# @lc app=leetcode id=2264 lang=python3
#
# [2264] Largest 3-Same-Digit Number in String
#


# @lc code=start
class Solution:
    def largestGoodInteger(self, num: str) -> str:
        result = "\0"

        for i in range(len(num) - 2):
            if num[i] == num[i + 1] == num[i + 2]:
                result = max(result, num[i])

        return "" if result == "\0" else result * 3


# @lc code=end
