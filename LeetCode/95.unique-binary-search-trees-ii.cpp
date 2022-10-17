/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
private:
    vector<TreeNode *> helper(int start, int end)
    {
        vector<TreeNode *> out;
        if (start > end)
        {
            out.push_back(nullptr);
            return out;
        }
        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> lefts = helper(start, i - 1);
            vector<TreeNode *> rights = helper(i + 1, end);
            for (int j = 0; j < lefts.size(); j++)
            {
                for (int k = 0; k < rights.size(); k++)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = lefts[j];
                    root->right = rights[k];
                    out.push_back(root);
                }
            }
        }
        return out;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
        {
            return vector<TreeNode *>(0);
        }
        return helper(1, n);
    }
};
// @lc code=end
