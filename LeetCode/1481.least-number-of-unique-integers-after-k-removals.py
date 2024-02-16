#
# @lc app=leetcode id=1481 lang=python3
#
# [1481] Least Number of Unique Integers after K Removals
#

# @lc code=start
from collections import Counter


class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        n = len(arr)
        counter = Counter(arr)
        freq_list = [0] * (n + 1)

        for n, f in counter.items():
            freq_list[f] += 1

        result = len(counter)

        for f in range(1, len(freq_list)):
            if k >= f * freq_list[f]:
                k -= f * freq_list[f]
                result -= freq_list[f]

            else:
                result -= k // f
                break

        return result


# @lc code=end
