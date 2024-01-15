#
# @lc app=leetcode id=2225 lang=python3
#
# [2225] Find Players With Zero or One Losses
#


# @lc code=start
class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        winners = set()
        losers = set()
        losers_plus_count = defaultdict(int)

        for matche in matches:
            winner, loser = matche
            winners.add(winner)
            losers.add(loser)
            losers_plus_count[loser] += 1

        only_winners = list(winners - losers)
        only_lost_one = [loser for loser in losers if losers_plus_count[loser] == 1]

        return [sorted(only_winners), sorted(only_lost_one)]


# @lc code=end
