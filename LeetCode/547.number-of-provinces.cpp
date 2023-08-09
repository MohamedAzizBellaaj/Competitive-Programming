/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution
{
private:
    unordered_set<int> set;
    void dfs(vector<vector<int>> &isConnected, int n, int node)
    {
        set.insert(node);
        for (int i = 0; i < n; ++i)
        {
            if (isConnected[node][i] and set.find(i) == set.end())
            {
                dfs(isConnected, n, i);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size(), out = 0, i = 0;
        while (set.size() < n and i < n)
        {
            if (set.find(i) == set.end())
            {
                dfs(isConnected, n, i);
                out++;
            }
            i++;
        }
        return out;
    }
};
// @lc code=end
