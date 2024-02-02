#
# @lc app=leetcode id=1291 lang=python3
#
# [1291] Sequential Digits
#


# @lc code=start
class Solution:
    def sequentialDigits(self, low, high):
        c = "123456789"
        result = []

        for i in range(len(c)):
            for j in range(i + 1, len(c) + 1):
                curr = int(c[i:j])
                if low <= curr <= high:
                    result.append(curr)

        result.sort()
        return result


# @lc code=end
