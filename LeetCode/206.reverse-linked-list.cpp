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
    // ListNode *reverseList(ListNode *head, ListNode *prev = nullptr)
    // {
    //     if (head == nullptr)
    //     {
    //         return nullptr;
    //     }
    //     if (head->next == nullptr)
    //     {
    //         head->next = prev;
    //         return head;
    //     }
    //     ListNode *aft = head->next;
    //     head->next = prev;
    //     return reverseList(aft, head);
    // }
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return node;
    }
};
// @lc code=end
