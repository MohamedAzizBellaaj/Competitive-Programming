/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
 */

// @lc code=start
class Solution
{
private:
    string intToBinaryString(int number, int n)
    {
        bitset<sizeof(int) * 8> binaryRepresentation(number);

        return binaryRepresentation.to_string().substr(sizeof(int) * 8 - n);
    }

public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string result;

        for (int i = 0; i < nums.size(); i++)
        {
            char curr = nums[i][i];
            result += curr == '0' ? '1' : '0';
        }

        return result;
    }
};
// @lc code=end
