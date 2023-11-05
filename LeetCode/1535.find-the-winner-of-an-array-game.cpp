/*
 * @lc app=leetcode id=1535 lang=cpp
 *
 * [1535] Find the Winner of an Array Game
 */

// @lc code=start
class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int maxElement = *max_element(arr.begin(), arr.end());
        int curr = arr.front(), winCount = 0, i = 1, n = arr.size();

        while (winCount < k and curr != maxElement and i < n)
        {
            if (curr > arr[i])
            {
                winCount++;
            }
            else
            {
                curr = arr[i];
                winCount = 1;
            }

            i++;
        }

        return curr;
    }
};
// @lc code=end
