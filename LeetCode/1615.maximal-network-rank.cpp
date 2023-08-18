/*
 * @lc app=leetcode id=1615 lang=cpp
 *
 * [1615] Maximal Network Rank
 */

// @lc code=start
class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        int count[n];
        memset(count, 0, sizeof(count));
        int roadsMatrix[n][n];
        memset(roadsMatrix, 0, sizeof(roadsMatrix));
        for (vector<int> road : roads)
        {
            count[road[0]]++;
            count[road[1]]++;
            roadsMatrix[road[0]][road[1]] = 1;
            roadsMatrix[road[1]][road[0]] = 1;
        }
        int out = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                out = max(out, count[i] + count[j] - roadsMatrix[i][j]);
            }
        }
        return out;
    }
};
// @lc code=end
