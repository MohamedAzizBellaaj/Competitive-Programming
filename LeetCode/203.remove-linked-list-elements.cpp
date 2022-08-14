/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *cur, *pre, *tmp;
        while (head != nullptr && head->val == val)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        else
        {
            cur = head;
            while (cur != nullptr)
            {
                if (cur->val == val)
                {
                    pre->next = cur->next;
                    tmp = cur;
                    cur = cur->next;
                    delete tmp;
                }
                else
                {
                    pre = cur;
                    cur = cur->next;
                }
            }
            return head;
        }
    }
};
// @lc code=end
