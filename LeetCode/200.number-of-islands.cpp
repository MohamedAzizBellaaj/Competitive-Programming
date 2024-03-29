/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
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
    void visit(vector<vector<char>> &grid, int i, int j)
    {
        grid[i][j] = '0';
        int m = grid.size(), n = grid.front().size();
        for (const auto &[x, y] : directions)
        {
            if (valid(i + y, j + x, m, n) && grid[i + y][x + j] == '1')
            {
                visit(grid, i + y, j + x);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int out = 0, m = grid.size(), n = grid.front().size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
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
