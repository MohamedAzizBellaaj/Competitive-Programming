/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    // void dfs(TreeNode *root, vector<int> &res)
    // {
    //     if (root)
    //     {
    //         res.push_back(root->val);
    //         dfs(root->left, res);
    //         dfs(root->right, res);
    //     }
    // }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> stack;
        if (root)
        {
            stack.push(root);
        }
        while (!stack.empty())
        {
            root = stack.top();
            res.push_back(stack.top()->val);
            stack.pop();
            if (root->right)
            {
                stack.push(root->right);
            }
            if (root->left)
            {
                stack.push(root->left);
            }
        }
        return res;
    }
};
// @lc code=end
