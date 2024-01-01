#
# @lc app=leetcode id=455 lang=python3
#
# [455] Assign Cookies
#


# @lc code=start
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        result = 0
        g.sort()
        s.sort()
        i = j = 0

        while j < len(s) and i < len(g):
            if g[i] <= s[j]:
                i += 1
                result += 1

            j += 1

        return result


# @lc code=end
