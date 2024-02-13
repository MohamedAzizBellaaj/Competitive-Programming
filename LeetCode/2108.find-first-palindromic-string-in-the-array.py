#
# @lc app=leetcode id=2108 lang=python3
#
# [2108] Find First Palindromic String in the Array
#


# @lc code=start
class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        def is_palindromic(s):
            n = len(s)
            for i in range(n // 2):
                if s[i] != s[n - 1 - i]:
                    return False

            return True

        for word in words:
            if is_palindromic(word):
                return word

        return ""


# @lc code=end
