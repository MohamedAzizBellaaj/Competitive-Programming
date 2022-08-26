/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string str)
    {
        stack<char> s;
        for (char &c : str)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                s.push(c);
            }
            else
            {
                if (s.empty())
                {
                    return false;
                }
                else if (s.top() == '(' && c == ')' || s.top() == '[' && c == ']' || s.top() == '{' && c == '}')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return s.empty();
    }
};
// @lc code=end
