/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution
{
public:
    bool visit(vector<vector<char>> &grid, int i, int j)
    {
        if (i < grid.size() && i >= 0 && j < grid[0].size() && j >= 0)
        {
            if (grid[i][j] == '1')
            {
                grid[i][j] = '0';
                return true;
            }
        }
        return false;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int out = 0;
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    out++;
                    q.push(make_pair(i, j));
                    grid[i][j] = '0';
                    while (!q.empty())
                    {
                        pair<int, int> p = q.front();
                        q.pop();
                        if (visit(grid, p.first + 1, p.second))
                        {
                            q.push(make_pair(p.first + 1, p.second));
                        }
                        if (visit(grid, p.first - 1, p.second))
                        {
                            q.push(make_pair(p.first - 1, p.second));
                        }
                        if (visit(grid, p.first, p.second + 1))
                        {
                            q.push(make_pair(p.first, p.second + 1));
                        }
                        if (visit(grid, p.first, p.second - 1))
                        {
                            q.push(make_pair(p.first, p.second - 1));
                        }
                    }
                }
            }
        }
        return out;
    }
};
// @lc code=end
