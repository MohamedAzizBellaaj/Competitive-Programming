/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int val, int color)
    {
        if (sr >= 0 && sr < image.size() && sc >= 0 && sc < image[0].size() && image[sr][sc] == val && image[sr][sc] != color)
        {
            image[sr][sc] = color;
            dfs(image, sr + 1, sc, val, color);
            dfs(image, sr - 1, sc, val, color);
            dfs(image, sr, sc + 1, val, color);
            dfs(image, sr, sc - 1, val, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};
// @lc code=end
