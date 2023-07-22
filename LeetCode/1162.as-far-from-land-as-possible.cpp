/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
class Solution
{
private:
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool valid(int y, int x, int n)
    {
        return y >= 0 and y < n and x >= 0 and x < n;
    }

public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size(), numberOf0 = 0, numberOf1 = 0, out = 0;
        for (vector<int> v : grid)
        {
            for (int x : v)
            {
                if (x == 0)
                {
                    numberOf0++;
                }
                else
                {
                    numberOf1++;
                }
            }
        }
        if (numberOf0 == n * n or numberOf1 == n * n)
        {
            return -1;
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty())
        {
            out++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> p = q.front();
                q.pop();
                int y = p.first, x = p.second;
                for (const auto [dx, dy] : directions)
                {
                    if (valid(y + dy, x + dx, n) && grid[y + dy][x + dx] == 0)
                    {
                        grid[y + dy][x + dx] = 1;
                        q.push({y + dy, x + dx});
                    }
                }
            }
        }
        return out - 1;
    }
};
// @lc code=end
