/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *reverseList(ListNode *head,ListNode *pre = nullptr)
    {
        if (head == nullptr)
        {
            return head;
        }
        if (head->next == nullptr)
        {
            head->next = pre;
            return head;
        }
        ListNode *aft = head->next;
        head->next = pre;
        pre = head;
        return reverseList(aft,pre);
    }
};
// @lc code=end
