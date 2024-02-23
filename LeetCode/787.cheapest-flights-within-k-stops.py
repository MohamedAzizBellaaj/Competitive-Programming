#
# @lc app=leetcode id=787 lang=python3
#
# [787] Cheapest Flights Within K Stops
#

# @lc code=start
import collections
import heapq


class Solution:
    def findCheapestPrice(
        self, n: int, flights: List[List[int]], src: int, dst: int, k: int
    ) -> int:
        graph = collections.defaultdict(dict)

        for s, d, w in flights:
            graph[s][d] = w

        pq = [(0, src, k + 1)]
        vis = [0] * n

        while pq:
            w, x, k = heapq.heappop(pq)

            if x == dst:
                return w

            if vis[x] >= k:
                continue

            vis[x] = k

            for y, dw in graph[x].items():
                heapq.heappush(pq, (w + dw, y, k - 1))

        return -1


# @lc code=end
