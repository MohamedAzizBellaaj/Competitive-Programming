#
# @lc app=leetcode id=1637 lang=python3
#
# [1637] Widest Vertical Area Between Two Points Containing No Points
#


# @lc code=start
class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        points = sorted(points, key=lambda x: x[0])
        result = 0

        for i in range(len(points) - 1):
            result = max(result, points[i + 1][0] - points[i][0])

        return result


# @lc code=end
