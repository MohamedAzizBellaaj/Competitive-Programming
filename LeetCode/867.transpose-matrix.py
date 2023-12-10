#
# @lc app=leetcode id=867 lang=python3
#
# [867] Transpose Matrix
#


# @lc code=start
class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        n = len(matrix[0])
        t_matrix = [[None] * m for _ in range(n)]

        for i in range(n):
            for j in range(m):
                t_matrix[i][j] = matrix[j][i]

        return t_matrix


# @lc code=end
