#
# @lc app=leetcode id=268 lang=python3
#
# [268] Missing Number
#


# @lc code=start
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        xor = 0
        i = 0

        while i < n:
            xor = xor ^ i ^ nums[i]
            i += 1

        return xor ^ i


# @lc code=end
