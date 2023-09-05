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
        Node *iter = head, *next;
        while (iter != nullptr)
        {
            next = iter->next;
            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = next;
            iter = next;
        }
        iter = head;
        while (iter != nullptr)
        {
            if (iter->random != nullptr)
            {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        Node *out = new Node(0), *iterCopy = out, *copy;
        iter = head;
        while (iter != nullptr)
        {
            copy = iter->next;
            iterCopy->next = copy;
            iterCopy = copy;
            next = iter->next->next;
            iter->next = next;
            iter = next;
        }
        return out->next;
    }
};
// @lc code=end
