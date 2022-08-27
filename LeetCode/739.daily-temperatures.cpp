/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> out(temperatures.size());
        stack<int> s;
        for (int i = temperatures.size() - 1; i >= 0; --i)
        {
            while (!s.empty() && temperatures[i] >= temperatures[s.top()])
            {
                s.pop();
            }
            if (s.empty())
            {
                out[i] = 0;
            }
            else
            {
                out[i] = s.top() - i;
            }
            s.push(i);
        }
        return out;
    }
};
// @lc code=end
