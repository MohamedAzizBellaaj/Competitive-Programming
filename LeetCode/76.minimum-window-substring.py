#
# @lc app=leetcode id=76 lang=python3
#
# [76] Minimum Window Substring
#

# @lc code=start
from collections import Counter, defaultdict


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "":
            return ""

        count_t = Counter(t)
        window = defaultdict(int)
        have, need = 0, len(count_t)
        result = [-1, -1]
        result_len = float("inf")
        l = 0

        for r in range(len(s)):
            c = s[r]
            if c in count_t:
                window[c] += 1
                if window[c] == count_t[c]:
                    have += 1

            while have == need:
                if (r - l + 1) < result_len:
                    result = [l, r]
                    result_len = r - l + 1

                c = s[l]
                if c in count_t:
                    window[c] -= 1
                    if window[c] < count_t[c]:
                        have -= 1

                l += 1

        l, r = result

        return s[l : r + 1] if result_len != float("inf") else ""


# @lc code=end
