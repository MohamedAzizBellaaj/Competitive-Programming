#
# @lc app=leetcode id=1642 lang=python3
#
# [1642] Furthest Building You Can Reach
#


# @lc code=start
import heapq


class Solution:
    def furthestBuilding(self, A, bricks, ladders):
        heap = []

        for i in range(len(A) - 1):
            d = A[i + 1] - A[i]

            if d > 0:
                heapq.heappush(heap, d)

            if len(heap) > ladders:
                bricks -= heapq.heappop(heap)
            if bricks < 0:
                return i

        return len(A) - 1


# @lc code=end
