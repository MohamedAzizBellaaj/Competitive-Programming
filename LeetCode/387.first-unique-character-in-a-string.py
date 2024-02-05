#
# @lc app=leetcode id=387 lang=python3
#
# [387] First Unique Character in a String
#

# @lc code=start
from collections import Counter


class Solution:
    def firstUniqChar(self, s: str) -> int:
        my_dict = {}
        for i, c in enumerate(s):
            if c in my_dict:
                my_dict[c][0] += 1

            else:
                my_dict[c] = [1, i]

        arr = []

        for value in my_dict.values():
            if value[0] == 1:
                arr.append(value[1])

        return min(arr) if arr else -1


# @lc code=end
