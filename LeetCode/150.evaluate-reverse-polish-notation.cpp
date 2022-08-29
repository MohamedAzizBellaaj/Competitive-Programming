/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stack;
        for (string &s : tokens)
            if (s == "+" || s == "-" || s == "*" || s == "/")
            {
                int op1, op2, res;
                op1 = stack.top();
                stack.pop();
                op2 = stack.top();
                stack.pop();
                if (s == "+")
                {
                    res = op2 + op1;
                }
                if (s == "-")
                {
                    res = op2 - op1;
                }
                if (s == "/")
                {
                    res = op2 / op1;
                }
                if (s == "*")
                {
                    res = op2 * op1;
                }
                stack.push(res);
            }
            else
            {
                stack.push(stoi(s));
            }
        return stack.top();
    }
};
// @lc code=end
