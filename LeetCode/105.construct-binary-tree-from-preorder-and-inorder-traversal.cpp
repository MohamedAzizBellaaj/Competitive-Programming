/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    int preInd = 0;
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[preInd++]);
        int i;
        for (i = 0; i <= end; i++)
        {
            if (inorder[i] == root->val)
            {
                break;
            }
        }
        root->left = helper(preorder, inorder, start, i - 1);
        root->right = helper(preorder, inorder, i + 1, end);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return helper(preorder, inorder, 0, preorder.size() - 1);
    }
};
// @lc code=end
