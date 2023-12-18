#
# @lc app=leetcode id=1913 lang=python3
#
# [1913] Maximum Product Difference Between Two Pairs
#


# @lc code=start
class Solution:
    def maxProductDifference(self, nums: List[int]) -> int:
        max = float("-inf")
        second_max = float("-inf")
        min = float("inf")
        second_min = float("inf")

        for i in nums:
            if max <= i:
                second_max = max
                max = i

            elif second_max <= i:
                second_max = i

            if min >= i:
                second_min = min
                min = i

            elif second_min >= i:
                second_min = i

        return max * second_max - min * second_min


# @lc code=end
