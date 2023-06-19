/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution
{
private:
    bool closerToX(int a, int b, int x)
    {
        return abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b);
    }

public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int left = 0, right = arr.size() - 1, middle, closestIndex = -1;
        while (left <= right)
        {
            middle = left + (right - left) / 2;
            if (arr[middle] > x)
            {
                right = middle - 1;
            }
            else if (arr[middle] < x)
            {
                left = middle + 1;
            }
            else
            {
                closestIndex = middle;
                break;
            }
        }
        if (closestIndex == -1)
        {
            if (right < 0)
            {
                closestIndex = left;
            }
            else if (left > arr.size() - 1)
            {
                closestIndex = right;
            }
            else
            {
                closestIndex = closerToX(arr[left], arr[right], x) ? left : right;
            }
        }
        deque<int> res;
        res.push_back(arr[closestIndex]);
        k--;
        int l = 1, r = 1;
        while (k > 0)
        {
            k--;
            if (closestIndex - l < 0)
            {
                res.push_back(arr[closestIndex + r]);
                r++;
            }
            else if (closestIndex + r > arr.size() - 1)
            {
                res.push_front(arr[closestIndex - l]);
                l++;
            }
            else
            {
                if (closerToX(arr[closestIndex - l], arr[closestIndex + r], x))
                {
                    res.push_front(arr[closestIndex - l]);
                    l++;
                }
                else
                {
                    res.push_back(arr[closestIndex + r]);
                    r++;
                }
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end
