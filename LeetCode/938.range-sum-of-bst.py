#
# @lc app=leetcode id=938 lang=python3
#
# [938] Range Sum of BST
#


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Python3 Solution
class Solution:
    def rangeSumBST(self, root: TreeNode, low: int, high: int) -> int:
        self.total_sum = 0

        def dfs(node):
            if not node:
                return

            if low <= node.val <= high:
                self.total_sum += node.val
                dfs(node.left)
                dfs(node.right)

            elif node.val < low:
                dfs(node.right)

            elif node.val > high:
                dfs(node.left)

        dfs(root)

        return self.total_sum


# @lc code=end
