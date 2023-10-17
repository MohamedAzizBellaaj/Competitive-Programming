/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
 */

// @lc code=start
class Solution
{
private:
    int findRoot(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        unordered_set<int> set;
        set.insert(leftChild.begin(), leftChild.end());
        set.insert(rightChild.begin(), rightChild.end());
        for (int i = 0; i < n; i++)
        {
            if (set.find(i) == set.end())
            {
                return i;
            }
        }
        return -1;
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        int root = findRoot(n, leftChild, rightChild);
        if (root == -1)
        {
            return false;
        }

        stack<int> stack({root});
        unordered_set<int> seen({root});

        while (!stack.empty())
        {
            int node = stack.top();
            stack.pop();
            int children[] = {leftChild[node], rightChild[node]};
            for (const int &child : children)
            {
                if (child != -1)
                {
                    if (seen.find(child) != seen.end())
                    {
                        return false;
                    }
                    stack.push(child);
                    seen.insert(child);
                }
            }
        }

        return seen.size() == n;
    }
};
// @lc code=end
