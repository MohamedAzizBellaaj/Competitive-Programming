/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    vector<int> findMode(TreeNode *root)
    {
        vector<int> result;
        int currentStreak = 0, currentVal = INT_MAX, maxStreak = 0;
        TreeNode *currentNode = root;
        while (currentNode != nullptr)
        {
            if (currentNode->left != nullptr)
            {
                TreeNode *neighbor = currentNode->left;
                while (neighbor->right != nullptr)
                {
                    neighbor = neighbor->right;
                }
                neighbor->right = currentNode;

                TreeNode *tmp = currentNode->left;
                currentNode->left = nullptr;
                currentNode = tmp;
            }
            else
            {
                if (currentNode->val == currentVal)
                {
                    currentStreak++;
                }
                else
                {
                    currentStreak = 0;
                    currentVal = currentNode->val;
                }

                if (currentStreak == maxStreak)
                {
                    result.push_back(currentNode->val);
                }
                else if (currentStreak > maxStreak)
                {
                    maxStreak = currentStreak;
                    result.clear();
                    result.push_back(currentNode->val);
                }

                currentNode = currentNode->right;
            }
        }

        return result;
    }
};
// @lc code=end
