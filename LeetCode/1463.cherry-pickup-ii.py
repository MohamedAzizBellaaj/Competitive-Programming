#
# @lc app=leetcode id=1463 lang=python3
#
# [1463] Cherry Pickup II
#


# @lc code=start
from itertools import product


class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])

        dp = [[0] * COLS for _ in range(COLS)]

        for r in range(ROWS - 1, -1, -1):
            cur_dp = [[0] * COLS for _ in range(COLS)]

            for c1 in range(COLS - 1):
                for c2 in range(c1 + 1, COLS):
                    max_cherries = 0
                    cherries = grid[r][c1] + grid[r][c2]
                    for c1_d, c2_d in product([-1, 0, 1], [-1, 0, 1]):
                        nc1, nc2 = c1 + c1_d, c2 + c2_d

                        if nc1 < 0 or nc2 == COLS:
                            continue

                        max_cherries = max(max_cherries, cherries + dp[nc1][nc2])

                    cur_dp[c1][c2] = max_cherries

            dp = cur_dp

        return dp[0][COLS - 1]


# @lc code=end
