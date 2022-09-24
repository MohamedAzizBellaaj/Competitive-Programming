/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    // ListNode *swapPairs(ListNode *head)
    // {
    //     if (!head || !head->next)
    //     {
    //         return head;
    //     }
    //     ListNode *tmp = head->next;
    //     head->next = tmp->next;
    //     tmp->next = head;
    //     head->next = swapPairs(head->next);
    //     return tmp;
    // }
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *out = head->next, *prev = new ListNode();
        while (head && head->next)
        {
            prev->next = head->next;
            head->next = prev->next->next;
            prev->next->next = head;
            prev = head;
            head = head->next;
        }
        return out;
    }
};
// @lc code=end
