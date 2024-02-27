#
# @lc app=leetcode id=543 lang=python3
#
# [543] Diameter of Binary Tree
#


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        max_diameter = 0

        def dfs(root):
            if root is None:
                return -1

            left = dfs(root.left)
            right = dfs(root.right)

            nonlocal max_diameter

            max_diameter = max(max_diameter, left + right + 2)

            return 1 + max(left, right)

        dfs(root)

        return max_diameter


# @lc code=end
