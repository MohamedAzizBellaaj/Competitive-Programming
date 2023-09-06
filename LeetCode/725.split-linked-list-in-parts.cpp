/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> out(k);
        ListNode *tmp = head;
        int n = 0;
        while (tmp != nullptr)
        {
            tmp = tmp->next;
            n++;
        }
        int minSize = n / k, rem = n % k;
        ListNode *curr = head;
        while (head != nullptr)
        {
            for (int i = 0; i < k; i++)
            {
                out[i] = head;
                for (int j = 0; j < minSize + (i < rem ? 1 : 0); j++)
                {
                    if (head != nullptr)
                    {
                        curr = head;
                        head = head->next;
                    }
                }
                if (head != nullptr)
                {
                    ListNode *next = curr->next;
                    curr->next = nullptr;
                    curr = next;
                    head = curr;
                }
            }
        }
        return out;
    }
};
// @lc code=end
