#
# @lc app=leetcode id=1347 lang=python3
#
# [1347] Minimum Number of Steps to Make Two Strings Anagram
#


# @lc code=start
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        count = collections.Counter(s)
        res = 0

        for c in t:
            if count[c] > 0:
                count[c] -= 1
            else:
                res += 1

        return res


# @lc code=end
