/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> res(n);
        for (int i = 1; i <= n; ++i)
        {
            string out = "";
            if (i % 3 == 0)
            {
                out += "Fizz";
            }
            if (i % 5 == 0)
            {
                out += "Buzz";
            }
            if (out=="")
            {
                out = to_string(i);
            }
            res[i - 1] = out;
        }
        return res;
    }
};
// @lc code=end
