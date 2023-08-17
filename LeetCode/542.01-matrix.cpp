/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution
{
private:
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool isValid(int y, int x, int m, int n)
    {
        return y >= 0 and y < m and x >= 0 and x < n;
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                }
                else
                {
                    mat[i][j] = -1;
                }
            }
        }
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> p = q.front();
                q.pop();
                int y = p.first, x = p.second;
                for (const auto &[dy, dx] : directions)
                {
                    if (isValid(y + dy, x + dx, m, n) and mat[y + dy][x + dx] == -1)
                    {
                        mat[y + dy][x + dx] = mat[y][x] + 1;
                        q.push({y + dy, x + dx});
                    }
                }
            }
        }
        return mat;
    }
};
// @lc code=end
