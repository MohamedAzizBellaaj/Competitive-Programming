/*
 * @lc app=leetcode id=1424 lang=cpp
 *
 * [1424] Diagonal Traverse II
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        vector<int> result;

        while (!queue.empty())
        {
            auto [row, col] = queue.front();
            queue.pop();
            result.push_back(nums[row][col]);

            if (col == 0 && row + 1 < nums.size())
            {
                queue.push({row + 1, col});
            }

            if (col + 1 < nums[row].size())
            {
                queue.push({row, col + 1});
            }
        }

        return result;
    }
};
// @lc code=end
