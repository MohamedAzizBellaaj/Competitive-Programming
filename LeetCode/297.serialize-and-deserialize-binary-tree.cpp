/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
        {
            return "null";
        }
        else
        {
            return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
        }
    }
    TreeNode *deserialize(string data)
    {
        istringstream ss(data);
        return helper(ss);
    }
    TreeNode *helper(istringstream &ss)
    {
        string s;
        ss >> s;
        if (s == "null")
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(s));
        root->left = helper(ss);
        root->right = helper(ss);
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
