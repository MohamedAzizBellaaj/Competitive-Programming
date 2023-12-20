#
# @lc app=leetcode id=2706 lang=python3
#
# [2706] Buy Two Chocolates
#


# @lc code=start
class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        cost = sum(nsmallest(2, prices))

        return money - cost if money >= cost else money


# @lc code=end
