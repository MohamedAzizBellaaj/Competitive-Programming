/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        bool hasCycle = false;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                hasCycle = true;
                break;
            }
        }
        if (hasCycle)
        {
            ListNode *tmp = head;
            while (true)
            {
                if (tmp == slow)
                {
                    return tmp;
                }
                tmp = tmp->next;
                slow = slow->next;
            }
        }
        return nullptr;
    }
};
// @lc code=end
