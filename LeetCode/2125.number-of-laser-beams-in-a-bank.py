#
# @lc app=leetcode id=2125 lang=python3
#
# [2125] Number of Laser Beams in a Bank
#


# @lc code=start
class Solution:
    def numberOfBeams(self, bank):
        result, temp = 0, 0

        for s in bank:
            n = s.count("1")

            if n == 0:
                continue

            result += temp * n
            temp = n

        return result


# @lc code=end
