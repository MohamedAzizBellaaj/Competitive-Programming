/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1, right = n, middle;
        while (left < right)
        {
            middle = left + (right - left) / 2;
            if (!isBadVersion(middle))
            {
                left = middle + 1;
            }
            else
            {
                right = middle;
            }
        }
        return right;
    }
};
// @lc code=end
