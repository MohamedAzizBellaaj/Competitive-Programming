/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *p = head;
        int length = 0;
        while (p != nullptr)
        {
            p = p->next;
            length++;
        }
        p = head;
        for (int i = 1; i < length / 2 + 1; ++i)
        {
            p = p->next;
        }
        return p;
    }
};
// @lc code=end
