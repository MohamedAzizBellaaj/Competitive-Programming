/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *parent = root, *baseChild, *currChild, *nextChild;
        while (parent)
        {
            while (parent->next && !parent->left && !parent->right)
            {
                parent = parent->next;
            }
            currChild = baseChild = parent->left ? parent->left : parent->right;
            while (currChild)
            {
                nextChild = nullptr;
                if (parent->right && currChild != parent->right)
                    nextChild = parent->right;
                else
                {
                    parent = parent->next;
                    while (parent && !parent->left && !parent->right)
                    {
                        parent = parent->next;
                    }
                    if (parent)
                    {
                        nextChild = parent->left ? parent->left : parent->right;
                    }
                }
                currChild->next = nextChild;
                currChild = nextChild;
            }
            parent = baseChild;
        }
        return root;
    }
};
// @lc code=end
