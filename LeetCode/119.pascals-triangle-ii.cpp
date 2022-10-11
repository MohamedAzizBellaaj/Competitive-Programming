/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution
{
    // private:
    //     vector<int> helper(int rowIndex, int curRow, vector<int> v)
    //     {
    //         if (curRow == rowIndex)
    //         {
    //             return v;
    //         }
    //         vector<int> out(v.size() + 1);
    //         out.front() = 1;
    //         out.back() = 1;
    //         for (int i = 1; i < out.size() - 1; ++i)
    //         {
    //             out[i] = v[i - 1] + v[i];
    //         }
    //         return helper(rowIndex, curRow + 1, out);
    //     }

public:
    // vector<int> getRow(int rowIndex)
    // {
    //     if (rowIndex == 0)
    //     {
    //         return {1};
    //     }
    //     if (rowIndex == 1)
    //     {
    //         return {1, 1};
    //     }
    //     vector<int> out = {1, 1};
    //     return helper(rowIndex, 1, out);
    // }
    vector<int> getRow(int rowIndex)
    {
        vector<int> out{1}, curr{1};
        for (int i = 1; i <= rowIndex; ++i)
        {
            out.push_back(1);
            for (int j = 1; j < i; ++j)
            {
                out[j] = curr[j] + curr[j - 1];
            }
            curr = out;
        }
        return out;
    }
};
// @lc code=end
