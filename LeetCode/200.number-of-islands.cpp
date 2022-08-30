/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution
{
public:
    void visit(vector<vector<char>> &grid, int i, int j)
    {
        if (i < grid.size() && i >= 0 && j < grid[0].size() && j >= 0)
        {
            if (grid[i][j] == '1')
            {
                grid[i][j] = '0';
                visit(grid, i + 1, j);
                visit(grid, i, j + 1);
                visit(grid, i - 1, j);
                visit(grid, i, j - 1);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int out = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
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
