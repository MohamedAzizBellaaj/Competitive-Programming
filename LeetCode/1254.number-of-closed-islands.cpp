/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
class Solution
{
private:
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool valid(int y, int x, int m, int n)
    {
        return y >= 0 && y < m && x >= 0 && x < n;
    }
    void visit(vector<vector<int>> &grid, int i, int j)
    {
        if (grid[i][j] == 0)
        {
            grid[i][j] = 1;
            int m = grid.size(), n = grid.front().size();
            for (const auto &[dx, dy] : directions)
            {
                if (valid(i + dy, j + dx, m, n) && grid[i + dy][j + dx] == 0)
                {
                    visit(grid, i + dy, j + dx);
                }
            }
        }
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int out = 0, m = grid.size(), n = grid.front().size();

        for (int i = 0; i < m; ++i)
        {
            visit(grid, i, 0);
            visit(grid, i, n - 1);
        }
        for (int j = 0; j < n; ++j)
        {
            visit(grid, 0, j);
            visit(grid, m - 1, j);
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {
                    out++;
                    visit(grid, i, j);
                }
            }
        }
        return out;
    }
};
// @lc code=end
