#
# @lc app=leetcode id=1043 lang=python3
#
# [1043] Partition Array for Maximum Sum
#


# @lc code=start
class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        dp = [0] * k
        dp[0] = arr[0]

        for i in range(1, n):
            cur_max = 0
            max_at_i = 0

            for j in range(i, max(-1, i - k), -1):
                cur_max = max(cur_max, arr[j])
                window_size = i - j + 1
                cur_sum = cur_max * window_size
                sub_sum = dp[(j - 1) % k] if j > 0 else dp[-1]
                max_at_i = max(max_at_i, cur_sum + sub_sum)

            dp[i % k] = max_at_i

        return dp[(n - 1) % k]


# @lc code=end
