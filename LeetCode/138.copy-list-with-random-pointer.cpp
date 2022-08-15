/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        Node *nhead = head;
        while (nhead)
        {
            Node *tmp = new Node(nhead->val);
            tmp->next = nhead->next;
            nhead->next = tmp;
            nhead = nhead->next->next;
        }
        nhead = head;
        Node *start = nhead->next, *buf = start;
        while (nhead)
        {
            if (nhead->random != nullptr)
            {
                buf->random = nhead->random->next;
            }
            nhead = nhead->next->next;
            buf = nhead ? nhead->next : nullptr;
        }
        nhead = head, buf = start;
        while (nhead)
        {
            nhead->next = nhead->next->next;
            nhead = nhead->next;
            buf->next = nhead ? nhead->next : nullptr;
            buf = buf->next;
        }
        return start;
    }
};
// @lc code=end
