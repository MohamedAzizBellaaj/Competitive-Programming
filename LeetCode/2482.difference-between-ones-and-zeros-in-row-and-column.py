#
# @lc app=leetcode id=2482 lang=python3
#
# [2482] Difference Between Ones and Zeros in Row and Column
#


# @lc code=start
class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        diff = [[0] * n for _ in range(m)]
        ones_row = [sum(row) for row in grid]

        ones_col = [0] * n
        for j in range(n):
            for i in range(m):
                ones_col[j] += grid[i][j]

        for i in range(m):
            for j in range(n):
                diff[i][j] = 2 * ones_row[i] + 2 * ones_col[j] - m - n

        return diff


# @lc code=end
