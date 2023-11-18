/*
 * @lc app=leetcode id=1838 lang=cpp
 *
 * [1838] Frequency of the Most Frequent Element
 */

// @lc code=start
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int left = 0;
        long long total = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            total += nums[right];

            if ((right - left + 1) * long(nums[right]) - total > k)
            {
                total -= nums[left];
                left++;
            }
        }

        return nums.size() - left;
    }
};
// @lc code=end
