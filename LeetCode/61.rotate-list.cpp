/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        int x = 1;
        if (head == nullptr || head->next == nullptr || k == 0)
        {
            return head;
        }
        ListNode *tmp = head, *pre;
        while (tmp->next)
        {
            x++;
            pre = tmp;
            tmp = tmp->next;
        }
        k %= x;
        if (k == 0)
        {
            return head;
        }
        while (true)
        {
            pre->next = nullptr;
            tmp->next = head;
            head = tmp;
            k--;
            if (k == 0)
            {
                return head;
            }
            while (tmp->next)
            {
                pre = tmp;
                tmp = tmp->next;
            }
        }
    }
};
// @lc code=end
