/*
 * @lc app=leetcode id=1326 lang=cpp
 *
 * [1326] Minimum Number of Taps to Open to Water a Garden
 */

// @lc code=start
class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        int maxReach[n + 1];
        memset(maxReach, 0, sizeof(maxReach));
        for (int i = 0; i < n + 1; i++)
        {
            int start = max(0, i - ranges[i]);
            int end = min(n, ranges[i] + i);
            maxReach[start] = max(maxReach[start], end);
        }
        
        int taps = 0, currEnd = 0, nextEnd = 0;
        for (int i = 0; i < n + 1; i++)
        {
            if (i > nextEnd)
            {
                return -1;
            }
            if (i > currEnd)
            {
                taps++;
                currEnd = nextEnd;
            }
            nextEnd = max(nextEnd, maxReach[i]);
        }
        return taps;
    }
};
// @lc code=end
