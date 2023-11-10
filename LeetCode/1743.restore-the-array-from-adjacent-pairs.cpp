/*
 * @lc app=leetcode id=1743 lang=cpp
 *
 * [1743] Restore the Array From Adjacent Pairs
 */

// @lc code=start
class Solution
{
private:
    vector<int> result;

    void dfs(int node, int prevNode, unordered_map<int, vector<int>> &graph)
    {
        result.push_back(node);
        for (const int &neighbor : graph[node])
        {
            if (neighbor != prevNode)
            {
                dfs(neighbor, node, graph);
            }
        }
    }

public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        unordered_map<int, vector<int>> graph;

        for (const vector<int> &pair : adjacentPairs)
        {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }

        int root;
        for (const auto &[node, neighbors] : graph)
        {
            if (neighbors.size() == 1)
            {
                root = node;
                break;
            }
        }

        dfs(root, INT_MAX, graph);

        return result;
    }
};
// @lc code=end
