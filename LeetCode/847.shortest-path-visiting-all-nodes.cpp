/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        int n = graph.size();
        if (n == 1)
        {
            return 0;
        }

        queue<pair<int, int>> q;
        for (int node = 0; node < n; node++)
        {
            q.push({node, (1 << node)});
        }

        int finalState = (1 << n) - 1, shortestPath = 0;

        vector<vector<bool>> visited(n, vector<bool>(finalState, false));

        while (!q.empty())
        {
            shortestPath++;
            int size = q.size();

            while (size--)
            {
                const auto [currNode, currState] = q.front();
                q.pop();

                for (int &nextNode : graph[currNode])
                {
                    int nextState = (currState | (1 << nextNode));
                    if (nextState == finalState)
                    {
                        return shortestPath;
                    }

                    if (!visited[nextNode][nextState])
                    {
                        visited[nextNode][nextState] = true;
                        q.push({nextNode, nextState});
                    }
                }
            }
        }
        return shortestPath;
    }
};
// @lc code=end
