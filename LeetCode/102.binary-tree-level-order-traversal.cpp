/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> out;
        vector<int> tmp;
        queue<TreeNode *> q;
        TreeNode *last;
        if (root)
        {
            q.push(root);
            last = root;
        }
        while (!q.empty())
        {
            TreeNode *node = q.front();
            tmp.push_back(node->val);
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
            if (node == last)
            {
                out.push_back(tmp);
                tmp.clear();
                last = q.back();
            }
            q.pop();
        }
        return out;
    }
};
// @lc code=end
