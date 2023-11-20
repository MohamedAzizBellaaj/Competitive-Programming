/*
 * @lc app=leetcode id=2391 lang=cpp
 *
 * [2391] Minimum Amount of Time to Collect Garbage
 */

// @lc code=start
class Solution
{
private:
    int collectGarbage(char type, vector<string> &garbage, vector<int> &travel)
    {
        int result = 0;
        int lastIndex = 0;

        for (int i = 0; i < garbage.size(); i++)
        {
            for (const char &c : garbage[i])
            {
                if (c == type)
                {
                    lastIndex = i;
                    result++;
                }
            }
        }

        if (lastIndex != 0)
        {
            result += travel[lastIndex - 1];
        }

        return result;
    }

public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        int result = 0;
        char garbageTypes[3] = {'M',
                                'P',
                                'G'};

        partial_sum(travel.begin(), travel.end(), travel.begin());

        for (const char &type : garbageTypes)
        {
            result += collectGarbage(type, garbage, travel);
        }

        return result;
    }
};
// @lc code=end
