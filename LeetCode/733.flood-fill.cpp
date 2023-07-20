/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
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
    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int originalColor)
    {
        image[sr][sc] = color;
        for (const auto &[x, y] : directions)
        {
            int m = image.size(), n = image.front().size();
            if (valid(sr + y, sc + x, m, n) && image[sr + y][sc + x] == originalColor)
            {
                dfs(image, sr + y, sc + x, color, originalColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (color != image[sr][sc])
        {
            dfs(image, sr, sc, color, image[sr][sc]);
        }
        return image;
    }
};
// @lc code=end
