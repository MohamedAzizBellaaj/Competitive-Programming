/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution
{
private:
    unordered_map<int, int> mem;

public:
    int fib(int n)
    {
        if (mem.find(n) != mem.end())
        {
            return mem[n];
        }
        if (n < 2)
        {
            return n;
        }
        int result = fib(n - 1) + fib(n - 2);
        mem[n] = result;
        return result;
    }
};
// @lc code=end
