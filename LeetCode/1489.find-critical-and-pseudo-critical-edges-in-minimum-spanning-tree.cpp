/*
 * @lc app=leetcode id=1489 lang=cpp
 *
 * [1489] Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
 */

// @lc code=start
class Solution
{
public:
    class UnionFind
    {
    public:
        vector<int> parent;
        vector<int> rank;
        int maxRank;

        UnionFind(int n)
        {
            parent.resize(n);
            rank.resize(n, 1);
            maxRank = 1;
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
            }
        }

        int find(int x)
        {
            while (x != parent[x])
            {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return parent[x];
        }

        bool unite(int x, int y)
        {
            int parentX = find(x), parentY = find(y);
            if (parentX != parentY)
            {
                if (rank[parentX] < rank[parentY])
                {
                    swap(parentX, parentY);
                }
                parent[parentY] = parentX;
                rank[parentX] += rank[parentY];
                maxRank = max(maxRank, rank[parentX]);
                return true;
            }
            return false;
        }
    };

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> newEdges = edges;
        int m = newEdges.size();
        for (int i = 0; i < m; i++)
        {
            newEdges[i].push_back(i);
        }
        sort(newEdges.begin(), newEdges.end(), [](auto &a, auto &b)
             { return a[2] < b[2]; });
        UnionFind uf(n);
        int mstWeight = 0;
        for (vector<int> &edge : newEdges)
        {
            if (uf.unite(edge[0], edge[1]))
            {
                mstWeight += edge[2];
            }
        }

        vector<int> critical, pseudoCritical;
        for (int i = 0; i < m; i++)
        {
            UnionFind ufIgnore(n);
            int ignoreWeight = 0;
            for (int j = 0; j < m; j++)
            {
                if (i != j and ufIgnore.unite(newEdges[j][0], newEdges[j][1]))
                {
                    ignoreWeight += newEdges[j][2];
                }
            }
            if (ufIgnore.maxRank < n or ignoreWeight > mstWeight)
            {
                critical.push_back(newEdges[i][3]);
            }
            else
            {
                UnionFind ufForce(n);
                ufForce.unite(newEdges[i][0], newEdges[i][1]);
                int forceWeight = newEdges[i][2];
                for (int j = 0; j < m; j++)
                {
                    if (ufForce.unite(newEdges[j][0], newEdges[j][1]))
                    {
                        forceWeight += newEdges[j][2];
                    }
                }
                if (forceWeight == mstWeight)
                {
                    pseudoCritical.push_back(newEdges[i][3]);
                }
            }
        }
        return {critical, pseudoCritical};
    }
};
// @lc code=end
