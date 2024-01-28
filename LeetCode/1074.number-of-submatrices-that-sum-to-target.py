#
# @lc app=leetcode id=1074 lang=python3
#
# [1074] Number of Submatrices That Sum to Target
#


# @lc code=start
class Solution:
    def numSubmatrixSumTarget(self, A, target):
        m, n = len(A), len(A[0])
        result = 0

        for row in A:
            for i in range(n - 1):
                row[i + 1] += row[i]

        for i in range(n):
            for j in range(i, n):
                c = defaultdict(int)
                cur, c[0] = 0, 1
                for k in range(m):
                    cur += A[k][j] - (A[k][i - 1] if i > 0 else 0)
                    result += c[cur - target]
                    c[cur] += 1

        return result


# @lc code=end
