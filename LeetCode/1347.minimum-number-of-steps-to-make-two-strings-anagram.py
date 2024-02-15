#
# @lc app=leetcode id=1347 lang=python3
#
# [1347] Minimum Number of Steps to Make Two Strings Anagram
#


# @lc code=start
from collections import Counter


class Solution:
    def minSteps(self, s: str, t: str) -> int:
        count = Counter(s)
        result = 0

        for c in t:
            if count[c] > 0:
                count[c] -= 1
            else:
                result += 1

        return result


# @lc code=end
