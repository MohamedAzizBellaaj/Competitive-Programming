#
# @lc app=leetcode id=1436 lang=python3
#
# [1436] Destination City
#


# @lc code=start
class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        grid = {city[0]: city[1] for city in paths}
        destination = paths[0][1]

        while destination in grid:
            destination = grid[destination]

        return destination


# @lc code=end
