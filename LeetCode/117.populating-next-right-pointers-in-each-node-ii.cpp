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
        Node *currParent = root, *baseChild, *currChild, *nextChild;
        while (currParent)
        {
            while (currParent->next && !currParent->left && !currParent->right)
            {
                currParent = currParent->next;
            }
            currChild = baseChild = currParent->left ? currParent->left : currParent->right;
            while (currChild)
            {
                nextChild = nullptr;
                if (currParent->right && currChild != currParent->right)
                    nextChild = currParent->right;
                else
                {
                    currParent = currParent->next;
                    while (currParent && !currParent->left && !currParent->right)
                    {
                        currParent = currParent->next;
                    }
                    if (currParent)
                    {
                        nextChild = currParent->left ? currParent->left : currParent->right;
                    }
                }
                currChild->next = nextChild;
                currChild = nextChild;
            }
            currParent = baseChild;
        }
        return root;
    }
};
// @lc code=end
