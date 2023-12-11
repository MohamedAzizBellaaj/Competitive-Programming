#
# @lc app=leetcode id=1287 lang=python3
#
# [1287] Element Appearing More Than 25% In Sorted Array
#


# @lc code=start
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        size = len(arr) // 4

        for i in range(len(arr) - size):
            if arr[i] == arr[i + size]:
                return arr[i]

        return -1


# @lc code=end
