/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int left = 0, right = letters.size() - 1, middle;
        while (left <= right)
        {
            middle = left + (right - left) / 2;
            if (letters[middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return right + 1 >= 0 && right + 1 <= letters.size() - 1 ? letters[right + 1] : letters.front();
    }
};
// @lc code=end
