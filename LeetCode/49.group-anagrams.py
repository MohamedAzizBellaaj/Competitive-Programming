#
# @lc app=leetcode id=49 lang=python3
#
# [49] Group Anagrams
#

# @lc code=start
from collections import Counter, defaultdict


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        my_dict = defaultdict(list)

        for str in strs:
            my_dict["".join(sorted(str))].append(str)

        return my_dict.values()


# @lc code=end
