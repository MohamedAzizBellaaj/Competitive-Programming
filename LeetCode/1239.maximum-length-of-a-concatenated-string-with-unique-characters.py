#
# @lc app=leetcode id=1239 lang=python3
#
# [1239] Maximum Length of a Concatenated String with Unique Characters
#


# @lc code=start
class Solution:
    def maxLength(self, A):
        dp = [set()]
        
        for a in A:
            if len(set(a)) < len(a):
                continue
            a = set(a)
            for c in dp[:]:
                if a & c:
                    continue
                dp.append(a | c)
                
        return max(len(a) for a in dp)


# @lc code=end
