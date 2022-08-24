/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution
{
private:
    string helper(string s, int pos, int dir)
    {
        s[pos] = (s[pos] - '0' + dir + 10) % 10 + '0';
        return s;
    }

public:
    int openLock(vector<string> &deadends, string target)
    {
        int dist = 0;
        queue<string> q({"0000"});
        bool visited[10000];
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < deadends.size(); i++)
        {
            visited[stoi(deadends[i])] = true;
        }
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string s = q.front();
                q.pop();
                if (!visited[stoi(s)])
                {
                    if (s == target)
                    {
                        return dist;
                    }
                    else
                    {
                        visited[stoi(s)] = true;
                        q.push(helper(s, 0, 1));
                        q.push(helper(s, 1, 1));
                        q.push(helper(s, 2, 1));
                        q.push(helper(s, 3, 1));
                        q.push(helper(s, 0, -1));
                        q.push(helper(s, 1, -1));
                        q.push(helper(s, 2, -1));
                        q.push(helper(s, 3, -1));
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};
// @lc code=end
