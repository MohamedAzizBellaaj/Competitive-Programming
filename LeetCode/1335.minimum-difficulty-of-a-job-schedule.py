#
# @lc app=leetcode id=1335 lang=python3
#
# [1335] Minimum Difficulty of a Job Schedule
#


# @lc code=start
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        if len(jobDifficulty) < d:
            return -1

        cache = {}

        def dfs(i, d, cur_max):
            if (i, d, cur_max) in cache:
                return cache[i, d, cur_max]

            if i == len(jobDifficulty):
                return 0 if d == 0 else float("inf")

            if d == 0:
                return float("inf")

            cur_max = max(cur_max, jobDifficulty[i])

            result = min(dfs(i + 1, d, cur_max), cur_max + dfs(i + 1, d - 1, -1))
            cache[(i, d, cur_max)] = result

            return result

        return dfs(0, d, -1)


# @lc code=end
