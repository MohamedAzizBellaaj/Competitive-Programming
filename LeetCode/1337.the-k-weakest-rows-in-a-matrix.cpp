/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

// @lc code=start
class Solution
{
private:
    static bool criterion(vector<int> &a, vector<int> &b)
    {
        int numbSoldiersA = accumulate(a.begin(), a.end(), 0) - a.back();
        int numbSoldiersB = accumulate(b.begin(), b.end(), 0) - b.back();
        return numbSoldiersA < numbSoldiersB or (numbSoldiersA == numbSoldiersB and a.back() < b.back());
    }

public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        for (int i = 0; i < mat.size(); i++)
        {
            mat[i].push_back(i);
        }
        sort(mat.begin(), mat.end(), criterion);
        vector<int> out(k);
        for (int i = 0; i < k; i++)
        {
            out[i] = mat[i].back();
        }
        return out;
    }
};
// @lc code=end
