/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *out = head;
        if (head == nullptr)
        {
            return nullptr;
        }
        if (head->child == nullptr)
        {
            flatten(head->next);
        }
        else
        {
            Node *tmp = head->child;
            while (tmp->next)
            {
                tmp = tmp->next;
            }
            tmp->next = head->next;
            if (head->next)
            {
                head->next->prev = tmp;
            }
            head->next = head->child;
            head->child->prev = head;
            head->child = nullptr;
            flatten(head->next);
        }
        return out;
    }
};
// @lc code=end
