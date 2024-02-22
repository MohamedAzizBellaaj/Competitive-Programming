#
# @lc app=leetcode id=997 lang=python3
#
# [997] Find the Town Judge
#


# @lc code=start
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if len(trust) == 0 and n == 1:
            return 1

        count = [0] * (n + 1)

        for person in trust:
            count[person[0]] -= 1
            count[person[1]] += 1

        for person in range(len(count)):
            if count[person] == n - 1:
                return person

        return -1


# @lc code=end
