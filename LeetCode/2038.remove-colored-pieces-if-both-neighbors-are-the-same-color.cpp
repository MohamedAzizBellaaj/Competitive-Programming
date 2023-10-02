/*
 * @lc app=leetcode id=2038 lang=cpp
 *
 * [2038] Remove Colored Pieces if Both Neighbors are the Same Color
 */

// @lc code=start
class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int count = 0;
        for (int i = 1; i < colors.size() - 1; i++)
        {
            if (colors[i - 1] == colors[i] and colors[i] == colors[i + 1])
            {
                if (colors[i] == 'A')
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        return count > 0;
    }
};
// @lc code=end
