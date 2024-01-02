#
# @lc app=leetcode id=2610 lang=python3
#
# [2610] Convert an Array Into a 2D Array With Conditions
#


# @lc code=start
class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        result = []
        counter = defaultdict(int)

        for num in nums:
            row = counter[num]
            if len(result) == row:
                result.append([])

            result[row].append(num)
            counter[num] += 1

        return result


# @lc code=end
