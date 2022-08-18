/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // bool isSymmetric(TreeNode *root)
    // {
    //     if (root == nullptr)
    //     {
    //         return true;
    //     }
    //     return isSymmetricTest(root->left, root->right);
    // }
    // bool isSymmetricTest(TreeNode *l, TreeNode *r)
    // {
    //     if (l == nullptr && r == nullptr)
    //     {
    //         return true;
    //     }
    //     if (l == nullptr ^ r == nullptr)
    //     {
    //         return false;
    //     }
    //     if (l->val != r->val)
    //     {
    //         return false;
    //     }
    //     else
    //     {
    //         return isSymmetricTest(l->left,r->right)&&isSymmetricTest(l->right,r->left);
    //     }
    // }
    bool equivalent(TreeNode *l, TreeNode *r)
    {
        if (l == nullptr && r == nullptr)
        {
            return true;
        }
        if (l == nullptr ^ r == nullptr)
        {
            return false;
        }
        else
        {
            return l->val == r->val;
        }
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        bool b = false;
        stack<TreeNode *> s;
        s.push(root->right);
        s.push(root->left);
        while (!s.empty())
        {
            TreeNode *l = s.top();
            s.pop();
            TreeNode *r = s.top();
            s.pop();
            b = equivalent(l, r);
            if (b)
            {
                if (l && r)
                {
                    s.push(r->left);
                    s.push(l->right);
                    s.push(l->left);
                    s.push(r->right);
                }
            }
            else
            {
                return false;
            }
        }
        return b;
    }
};
// @lc code=end
