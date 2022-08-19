/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    int ind = 0;
    unordered_map<int, int> m;
    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(postorder[postorder.size() - 1 - ind++]);
        // int i = start;
        // for (; i <= end; i++)
        // {
        //     if (inorder[i] == root->val)
        //     {
        //         break;
        //     }
        // }
        root->right = helper(inorder, postorder, m[root->val] + 1, end);
        root->left = helper(inorder, postorder, start, m[root->val] - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < postorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        return helper(inorder, postorder, 0, postorder.size() - 1);
    }
};
// @lc code=end
