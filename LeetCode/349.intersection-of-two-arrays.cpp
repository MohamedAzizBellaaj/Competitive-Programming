/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        vector<int> out;
        for (const int &i : set1)
        {
            if (set2.find(i) != set2.end())
            {
                out.push_back(i);
            }
        }
        return out;
    }
};
// @lc code=end
