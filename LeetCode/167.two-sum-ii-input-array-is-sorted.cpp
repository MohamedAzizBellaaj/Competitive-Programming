/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;
        while (left <= right)
        {
            if (numbers[left] + numbers[right] > target)
            {
                right--;
            }
            else if (numbers[left] + numbers[right] < target)
            {
                left++;
            }
            else
            {
                return vector<int>{left + 1, right + 1};
            }
        }
        return vector<int>{left + 1, right + 1};
    }
};
// @lc code=end
