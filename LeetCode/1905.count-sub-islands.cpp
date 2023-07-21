/*
 * @lc app=leetcode id=1905 lang=cpp
 *
 * [1905] Count Sub Islands
 */

// @lc code=start
class Solution
{
private:
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool valid(int y, int x, int m, int n)
    {
        return y >= 0 and y < m and x >= 0 and x < n;
    }
    bool visit(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j)
    {
        if (grid2[i][j] == 1 and grid1[i][j] == 0)
        {
            return false;
        }
        bool flag = true;
        grid2[i][j] = 0, grid1[i][j] = 0;
        int m = grid2.size(), n = grid1.front().size();
        for (const auto &[dx, dy] : directions)
        {
            if (valid(i + dy, j + dx, m, n) and grid2[i + dy][j + dx] == 1)
            {
                flag &= visit(grid1, grid2, i + dy, j + dx);
            }
        }
        return flag;
    }

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int out = 0, m = grid2.size(), n = grid1.front().size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid2[i][j] == 1)
                {
                    out += visit(grid1, grid2, i, j);
                }
            }
        }
        return out;
    }
};
// @lc code=end
