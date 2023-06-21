/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> m;
        for (const int &x : nums1)
        {
            m[x]++;
        }
        vector<int> out;
        for (const int &x : nums2)
        {
            if (m.find(x) != m.end() && m[x] > 0)
            {
                m[x]--;
                out.push_back(x);
            }
        }
        return out;
    }
};
// @lc code=end
