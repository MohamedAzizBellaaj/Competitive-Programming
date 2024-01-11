#
# @lc app=leetcode id=1026 lang=python3
#
# [1026] Maximum Difference Between Node and Ancestor
#


# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root):
        v = 0

        def dfs(root):
            if root is None:
                return float("inf"), float("-inf")

            nonlocal v
            left_min, left_max = dfs(root.left)
            right_min, right_max = dfs(root.right)

            cur_min = min(root.val, left_min, right_min)
            cur_max = max(root.val, left_max, right_max)

            v = max(v, root.val - cur_min, cur_max - root.val)

            return cur_min, cur_max

        dfs(root)

        return v


# @lc code=end
