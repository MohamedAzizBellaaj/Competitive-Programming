/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(), *out = head;
        int c = 0;
        while (l1 || l2 || c == 1)
        {
            c += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            ListNode *tmp = new ListNode(c % 10);
            head->next = tmp;
            head = head->next;
            c /= 10;
            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        return out->next;
    }
};
// @lc code=end
