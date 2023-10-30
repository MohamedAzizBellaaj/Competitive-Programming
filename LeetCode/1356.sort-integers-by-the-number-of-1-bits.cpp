/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
class Solution
{
private:
    static int countSetBits(int n)
    {
        int count = 0;
        while (n > 0)
        {
            n &= (n - 1);
            count++;
        }
        return count;
    }

    static bool compare(const int &a, const int &b)
    {
        if (countSetBits(a) == countSetBits(b))
        {
            return a < b;
        }

        return countSetBits(a) < countSetBits(b);
    }

public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), compare);

        return arr;
    }
};
// @lc code=end
