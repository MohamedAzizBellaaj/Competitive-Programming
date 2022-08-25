/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        int out = 0;
        vector<int> arr;
        for (int i = 1; i * i <= n; i++)
        {
            arr.push_back(i * i);
        }
        bool visited[10001];
        memset(visited, false, sizeof(visited));
        queue<int> q({n});
        while (!q.empty())
        {
            int size = q.size(), x;
            for (int i = 0; i < size; i++)
            {
                x = q.front();
                q.pop();
                if (x == 0)
                {
                    return out;
                }
                else if (!visited[x])
                {
                    visited[x] = true;
                    for (int j = arr.size() - 1; j >= 0; j--)
                    {
                        if (x >= arr[j] && !visited[x - arr[j]])
                        {
                            q.push(x - arr[j]);
                        }
                    }
                }
            }
            out++;
        }
        return out;
    }
};
// @lc code=end
