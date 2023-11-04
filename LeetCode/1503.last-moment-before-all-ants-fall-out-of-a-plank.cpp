/*
 * @lc app=leetcode id=1503 lang=cpp
 *
 * [1503] Last Moment Before All Ants Fall Out of a Plank
 */

// @lc code=start
class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int result = 0;

        for (const int &num : left)
        {
            result = max(result, num);
        }
        for (const int &num : right)
        {
            result = max(result, n - num);
        }

        return result;
    }
};
// @lc code=end
