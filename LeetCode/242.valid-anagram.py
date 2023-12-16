#
# @lc app=leetcode id=242 lang=python3
#
# [242] Valid Anagram
#


# @lc code=start
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        from collections import Counter

        car_count = Counter(s)

        for character in t:
            if character in car_count and car_count[character] > 0:
                car_count[character] -= 1

            else:
                return False

        for value in car_count.values():
            if value != 0:
                return False

        return True


# @lc code=end
