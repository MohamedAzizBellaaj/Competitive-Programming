#
# @lc app=leetcode id=1496 lang=python3
#
# [1496] Path Crossing
#


# @lc code=start
class Solution:
    def isPathCrossing(self, path: str) -> bool:
        cur_position = (0, 0)
        move = {"N": (-1, 0), "S": (1, 0), "E": (0, -1), "W": (0, 1)}
        location_set = {cur_position}

        for direction in path:
            y, x = cur_position
            dy, dx = move[direction]
            cur_position = (y + dy, x + dx)

            if cur_position in location_set:
                return True

            location_set.add(cur_position)

        return False


# @lc code=end
