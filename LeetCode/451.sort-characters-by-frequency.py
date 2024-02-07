#
# @lc app=leetcode id=451 lang=python3
#
# [451] Sort Characters By Frequency
#


# @lc code=start
from collections import Counter


class Solution:
    def frequencySort(self, s: str) -> str:

        my_dict = Counter(s)
        tmp = []

        for key, value in my_dict.items():
            tmp.append((key, value))

        tmp.sort(key=lambda x: x[1], reverse=True)

        return "".join([x[0] * x[1] for x in tmp])


# @lc code=end
