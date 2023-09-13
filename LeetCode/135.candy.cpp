/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution
{

public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        int out = n, i = 1;
        while (i < n)
        {
            while (i < n and ratings[i] == ratings[i - 1])
            {
                i++;
            }

            int peak = 0;
            while (i < n and ratings[i] > ratings[i - 1])
            {
                peak++;
                out += peak;
                i++;
            }

            int valley = 0;
            while (i < n and ratings[i] < ratings[i - 1])
            {
                valley++;
                out += valley;
                i++;
            }

            out -= min(peak, valley);
        }
        return out;
    }
};
// @lc code=end
