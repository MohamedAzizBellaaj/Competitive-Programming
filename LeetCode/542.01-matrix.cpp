/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> out(m, vector<int>(n));
        queue<pair<int, int>> q;
        bool visited[m][n];
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    out[i][j] = 0;
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int dist = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int k = 0; k < sz; k++)
            {
                auto [i, j] = q.front();
                q.pop();
                if (mat[i][j] == 1)
                {
                    out[i][j] = dist;
                }
                for (auto &dir : directions)
                {
                    int ni = i + dir.first, nj = j + dir.second;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj])
                    {
                        visited[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
            dist++;
        }
        return out;
    }
};
// @lc code=end
