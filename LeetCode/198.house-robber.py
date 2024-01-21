#
# @lc app=leetcode id=198 lang=python3
#
# [198] House Robber
#


# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        choice1 = nums[0]
        choice2 = 0
        result = choice1

        for i in range(1, n):
            result = max(choice1, nums[i] + choice2)

            choice2 = choice1
            choice1 = result

        return result


# @lc code=end
