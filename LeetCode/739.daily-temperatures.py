#
# @lc app=leetcode id=739 lang=python3
#
# [739] Daily Temperatures
#


# @lc code=start
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        answer = [0] * len(temperatures)

        for i, temperature in enumerate(temperatures):
            while stack and stack[-1][0] < temperature:
                _, k = stack.pop()
                answer[k] = i - k

            stack.append((temperature, i))

        return answer


# @lc code=end
