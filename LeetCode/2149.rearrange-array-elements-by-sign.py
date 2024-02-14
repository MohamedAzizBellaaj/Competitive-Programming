#
# @lc app=leetcode id=2149 lang=python3
#
# [2149] Rearrange Array Elements by Sign
#

# @lc code=start
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0] * n
        pos_index, neg_index = 0, 1

        for i in range(n):
            if nums[i] > 0:
                result[pos_index] = nums[i]
                pos_index += 2
            else:
                result[neg_index] = nums[i]
                neg_index += 2

        return result
# @lc code=end

