/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> rows;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> currentRow(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                currentRow[j] = rows[i - 1][j] + rows[i - 1][j - 1];
            }
            rows.push_back(currentRow);
        }
        return rows;
    }
};
// @lc code=end
