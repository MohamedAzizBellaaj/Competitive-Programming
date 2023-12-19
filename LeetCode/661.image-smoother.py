#
# @lc app=leetcode id=661 lang=python3
#
# [661] Image Smoother
#


# @lc code=start
from re import S


class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m = len(img)
        n = len(img[0])
        result = [[0] * n for _ in range(m)]
        dir = [
            (0, 0),
            (0, 1),
            (0, -1),
            (1, 0),
            (-1, 0),
            (1, 1),
            (1, -1),
            (-1, 1),
            (-1, -1),
        ]

        def is_valid(y, x, m, n):
            return y >= 0 and y < m and x >= 0 and x < n

        for i in range(m):
            for j in range(n):
                total, nb = 0, 0

                for dx, dy in dir:
                    if is_valid(i + dy, j + dx, m, n):
                        total += img[i + dy][j + dx] & 255
                        nb += 1

                img[i][j] |= (total // nb) << 8

        for i in range(m):
            for j in range(n):
                img[i][j] >>= 8

        return img


# @lc code=end
