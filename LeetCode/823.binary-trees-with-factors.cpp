/*
 * @lc app=leetcode id=823 lang=cpp
 *
 * [823] Binary Trees With Factors
 */

// @lc code=start
class Solution
{
private:
    int mod = 1e9 + 7;

public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        unordered_map<unsigned long long, unsigned long long> subTreeCount;

        for (const int &root : arr)
        {
            subTreeCount[root] = 1;

            for (const int &factor : arr)
            {
                if (factor >= root)
                {
                    break;
                }

                if (root % factor == 0 && subTreeCount.find(root / factor) != subTreeCount.end())
                {
                    subTreeCount[root] += subTreeCount[factor] * subTreeCount[root / factor];
                }
            }
        }

        long totalTrees = 0;
        for (const auto &entry : subTreeCount)
        {
            totalTrees += entry.second;
        }

        return totalTrees % mod;
    }
};
// @lc code=end
