/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        unordered_set<int> set;
        stack<int> stack;
        stack.push(0);
        while (!stack.empty())
        {
            int room_num = stack.top();
            stack.pop();
            set.insert(room_num);
            for (int &room : rooms[room_num])
            {
                if (set.find(room) == set.end())
                {
                    stack.push(room);
                }
            }
        }
        return set.size() == rooms.size();
    }
};
// @lc code=end
