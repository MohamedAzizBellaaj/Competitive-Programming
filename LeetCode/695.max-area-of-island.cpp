/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
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
    int visit(vector<vector<int>> &grid, int i, int j)
    {
        grid[i][j] = 0;
        int out = 1, m = grid.size(), n = grid.front().size();
        for (const auto &[dx, dy] : directions)
        {
            if (valid(i + dy, j + dx, m, n) && grid[i + dy][j + dx] == 1)
            {
                out += visit(grid, i + dy, j + dx);
            }
        }
        return out;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int out = 0, m = grid.size(), n = grid.front().size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    out = max(out, visit(grid, i, j));
                }
            }
        }
        return out;
    }
};
// @lc code=end
