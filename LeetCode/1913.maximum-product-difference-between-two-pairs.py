#
# @lc app=leetcode id=1913 lang=python3
#
# [1913] Maximum Product Difference Between Two Pairs
#


# @lc code=start
class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        max = second_max = 0
        min = second_min = 1e4

        for i in nums:
            if max <= i:
                max, second_max = i, max

            elif second_max <= i:
                second_max = i

            if min >= i:
                min, second_min = i, min

            elif second_min >= i:
                second_min = i

        return max * second_max - min * second_min


# @lc code=end
