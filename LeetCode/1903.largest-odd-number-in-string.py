#
# @lc app=leetcode id=1903 lang=python3
#
# [1903] Largest Odd Number in String
#


# @lc code=start
class Solution:
    def largestOddNumber(self, num: str) -> str:
        return num[: 1 + max(num.rfind(c) for c in "13579")]


# @lc code=end
