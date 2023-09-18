/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in rowA Matrix
 */

// @lc code=start
class Solution
{
private:
    int helper(vector<int> &row)
    {
        int left = 0, right = row.size(), middle;
        while (left < right)
        {
            middle = left + (right - left) / 2;
            if (row[middle] == 1)
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

public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = {helper(mat[i]), i};
        }
        sort(v.begin(), v.end());
        vector<int> out(k);
        for (int i = 0; i < k; i++)
        {
            out[i] = v[i].second;
        }
        return out;
    }
};
// @lc code=end
