#
# @lc app=leetcode id=2385 lang=python3
#
# [2385] Amount of Time for Binary Tree to Be Infected
#


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         val = val
#         left = left
#         right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        max_distance = 0

        def traverse(root, start):
            nonlocal max_distance
            depth = 0
            
            if root is None:
                return depth

            left_depth = traverse(root.left, start)
            right_depth = traverse(root.right, start)

            if root.val == start:
                max_distance = max(left_depth, right_depth)
                depth = -1
            elif left_depth >= 0 and right_depth >= 0:
                depth = max(left_depth, right_depth) + 1
            else:
                distance = abs(left_depth) + abs(right_depth)
                max_distance = max(max_distance, distance)
                depth = min(left_depth, right_depth) - 1

            return depth

        traverse(root, start)

        return max_distance


# @lc code=end
