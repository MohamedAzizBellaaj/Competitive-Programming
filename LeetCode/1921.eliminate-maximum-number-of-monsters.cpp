/*
 * @lc app=leetcode id=1921 lang=cpp
 *
 * [1921] Eliminate Maximum Number of Monsters
 */

// @lc code=start
class Solution
{
private:
    static bool helper(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        else
        {
            return a.first < b.first;
        }
    }

public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<float> arrival(n);
        for (int i = 0; i < n; i++)
        {
            arrival[i] = ((float)dist[i] / speed[i]);
        }

        sort(arrival.begin(), arrival.end());
        int i = 0;

        while (i < n and arrival[i] > i)
        {
            i++;
        }

        return i;
    }
};
// @lc code=end
