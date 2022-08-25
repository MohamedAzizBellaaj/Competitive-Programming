/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack
{
public:
    int min;
    stack<int> s;
    stack<int> smin;

    void push(int val)
    {
        s.push(val);
        if (smin.empty() || val <= smin.top())
        {
            smin.push(val);
        }
    }

    void pop()
    {
        if (s.top() == smin.top())
        {
            smin.pop();
        }
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return smin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
