#
# @lc app=leetcode id=19 lang=python3
#
# [19] Remove Nth Node From End of List
#


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head, n):
        left = right = head

        for _ in range(n):
            right = right.next

        if right is None:
            return head.next

        while right.next:
            right = right.next
            left = left.next

        left.next = left.next.next

        return head


# @lc code=end
