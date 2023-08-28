/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack
{
private:
    queue<int> q;

public:
    void push(int x)
    {
        unsigned long long size = q.size();
        q.push(x);
        while (size > 0)
        {
            q.push(q.front());
            q.pop();
            size--;
        }
    }

    int pop()
    {
        int back = q.front();
        q.pop();
        return back;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
