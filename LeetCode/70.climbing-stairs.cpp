/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
private:
    unordered_map<int, int> m;

public:
    int climbStairs(int n)
    {
        if (m.find(n) != m.end())
        {
            return m[n];
        }
        if (n <= 2)
        {
            return n;
        }
        int result = climbStairs(n - 1) + climbStairs(n - 2);
        m[n] = result;
        return m[n];
    }
};
// @lc code=end
