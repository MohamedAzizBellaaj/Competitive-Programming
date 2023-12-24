#
# @lc app=leetcode id=1758 lang=python3
#
# [1758] Minimum Changes To Make Alternating Binary String
#


# @lc code=start
class Solution:
    def minOperations(self, s: str) -> int:
        start0 = 0

        for i in range(len(s)):
            if i % 2 == 0 and s[i] == "1":
                start0 += 1

            if i % 2 == 1 and s[i] == "0":
                start0 += 1

        return min(start0, len(s) - start0)


# @lc code=end
