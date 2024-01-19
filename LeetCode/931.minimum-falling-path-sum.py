#
# @lc app=leetcode id=931 lang=python3
#
# [931] Minimum Falling Path Sum
#


# @lc code=start
class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        directions = [(1, -1), (1, 0), (1, 1)]
        memo = {}

        def is_valid(row, col, n):
            return 0 <= row < n and 0 <= col < n

        def dfs(row, col, matrix):
            if row == len(matrix) - 1:
                return matrix[row][col]

            if (row, col) in memo:
                return memo[(row, col)]

            result = float("inf")
            for dy, dx in directions:
                if is_valid(row + dy, col + dx, len(matrix)):
                    result = min(
                        result, matrix[row][col] + dfs(row + dy, col + dx, matrix)
                    )

            memo[(row, col)] = result
            
            return result

        result = float("inf")
        for col in range(len(matrix)):
            result = min(result, dfs(0, col, matrix))

        return result


# @lc code=end
