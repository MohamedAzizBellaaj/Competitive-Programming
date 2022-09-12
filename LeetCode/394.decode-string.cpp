/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> st;
        for (char const &c : s)
        {
            if (c != ']')
            {
                st.push(c);
            }
            else
            {
                string curr_str = "";
                while (st.top() != '[')
                {
                    curr_str = st.top() + curr_str;
                    st.pop();
                }
                st.pop();
                string number = "";
                while (!st.empty() && isdigit(st.top()))
                {
                    number = st.top() + number;
                    st.pop();
                }
                int k_time = stoi(number);
                while (k_time--)
                {
                    for (char const &p : curr_str)
                        st.push(p);
                }
            }
        }
        s = "";
        while (!st.empty())
        {
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};
// @lc code=end
