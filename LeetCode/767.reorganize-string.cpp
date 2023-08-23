/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution
{
public:
    string reorganizeString(string s)
    {
        string out;
        unordered_map<char, int> count;
        for (const char c : s)
        {
            count[c]++;
        }
        priority_queue<pair<int, char>> maxHeap;
        for (const auto &[character, freq] : count)
        {
            maxHeap.push({freq, character});
        }
        while (maxHeap.size() > 1)
        {
            auto [freq1, character1] = maxHeap.top();
            maxHeap.pop();
            auto [freq2, character2] = maxHeap.top();
            maxHeap.pop();
            out += character1;
            out += character2;
            if (freq1 > 1)
            {
                maxHeap.push({freq1 - 1, character1});
            }
            if (freq2 > 1)
            {
                maxHeap.push({freq2 - 1, character2});
            }
        }
        if (maxHeap.size() > 0)
        {
            const auto &[freq, character] = maxHeap.top();
            if (freq == 1)
            {
                out += character;
            }
            else
            {
                return "";
            }
        }
        return out;
    }
};
// @lc code=end
