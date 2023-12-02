#
# @lc app=leetcode id=1160 lang=python3
#
# [1160] Find Words That Can Be Formed by Characters
#


# @lc code=start
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        from collections import Counter

        result = 0
        my_counter = Counter(chars)

        for word in words:
            good = True
            word_counter = Counter(word)
            for char, frequency in word_counter.items():
                if frequency > my_counter[char]:
                    good = False
            if good:
                result += len(word)

        return result


# @lc code=end
