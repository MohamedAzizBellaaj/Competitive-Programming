#
# @lc app=leetcode id=948 lang=python3
#
# [948] Bag of Tokens
#


# @lc code=start
class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        tokens.sort()
        left = 0
        right = len(tokens) - 1
        max_score = 0
        score = 0

        while left <= right:
            if power >= tokens[left]:
                power -= tokens[left]
                score += 1
                max_score = max(max_score, score)
                left += 1

            elif score >= 1:
                power += tokens[right]
                score -= 1
                right -= 1

            else:
                break

        return max_score


# @lc code=end
