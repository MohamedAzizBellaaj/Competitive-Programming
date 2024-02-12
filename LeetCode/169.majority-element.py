#
# @lc app=leetcode id=169 lang=python3
#
# [169] Majority Element
#


# @lc code=start
from collections import Counter


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        my_dict = Counter(nums)

        for key, value in my_dict.items():
            if value >= len(nums) / 2:
                return key

        return -1


# @lc code=end
