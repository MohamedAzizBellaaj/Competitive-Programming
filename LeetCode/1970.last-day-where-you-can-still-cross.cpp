/*
 * @lc app=leetcode id=1970 lang=cpp
 *
 * [1970] Last Day Where You Can Still Cross
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> fillMatrix(int row, int col, vector<vector<int>> &cells, int n)
    {
        vector<vector<int>> m(row, vector<int>(col, 0));
        for (size_t i = 0; i < n; i++)
        {
            int ri = cells[i][0] - 1, ci = cells[i][1] - 1;
            m[ri][ci] = 1;
        }
        return m;
    }
    bool isValid(int row, int col, int i, int j)
    {
        return i >= 0 && i < row && j >= 0 && j < col;
    }

    bool canTraverse(int row, int col, vector<vector<int>> &cells, int n)
    {
        vector<vector<int>> m = fillMatrix(row, col, cells, n);
        bool visited[row][col];
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> q;
        for (int i = 0; i < col; i++)
        {
            if (m[0][i] == 0)
            {
                visited[0][i] = true;
                q.push({0, i});
            }
        }
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty())
        {
            int sz = q.size();
            for (size_t i = 0; i < sz; i++)
            {
                pair<int, int> p = q.front();
                q.pop();
                int y = p.first, x = p.second;
                if (y == row - 1)
                {
                    return true;
                }
                for (const auto &[dy, dx] : dir)
                {
                    if (isValid(row, col, y + dy, x + dx) && !visited[y + dy][x + dx] && m[y + dy][x + dx] == 0)
                    {
                        q.push({y + dy, x + dx});
                        visited[y + dy][x + dx] = true;
                    }
                }
            }
        }
        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int left = 0, right = cells.size() - 1, middle, index = 0;
        while (left <= right)
        {
            middle = left + (right - left) / 2;
            if (canTraverse(row, col, cells, middle))
            {
                index = middle;
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        return index;
    }
};
// @lc code=end
