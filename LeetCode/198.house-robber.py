#
# @lc app=leetcode id=198 lang=python3
#
# [198] House Robber
#


# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        # memo = [-1] * len(nums)

        # def helper(i, nums):
        #     if i >= len(nums):
        #         return 0

        #     if memo[i] != -1:
        #         return memo[i]

        #     result = max(nums[i] + helper(i + 2, nums), helper(i + 1, nums))
        #     memo[i] = result

        #     return result

        # return helper(0, nums)

        # n = len(nums)
        # dp = [0] * n
        # dp[-1] = nums[-1]

        # for i in range(n - 2, -1, -1):
        #     choice1 = nums[i] + (dp[i + 2] if i < n - 2 else 0)
        #     choice2 = dp[i + 1]

        #     dp[i] = max(choice1, choice2)

        # return dp[0]

        n = len(nums)
        next_house = nums[-1]
        second_next_house = 0
        result = next_house

        for i in range(n - 2, -1, -1):
            result = max(next_house, nums[i] + second_next_house)

            second_next_house = next_house
            next_house = result

        return result


# @lc code=end
