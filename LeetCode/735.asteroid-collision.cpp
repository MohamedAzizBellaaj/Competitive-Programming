/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> s;
        for (int asteroid : asteroids)
        {
            if (s.empty())
            {
                s.push(asteroid);
            }
            else
            {
                int prevAsteroid = s.top();
                if (prevAsteroid <= 0 || (prevAsteroid >= 0 && asteroid >= 0))
                {
                    s.push(asteroid);
                }
                else
                {
                    while (prevAsteroid >= 0 && abs(prevAsteroid) < abs(asteroid) && !s.empty())
                    {
                        s.pop();
                        prevAsteroid = !s.empty() ? s.top() : 0;
                    }
                    if (prevAsteroid <= 0 || s.empty())
                    {
                        s.push(asteroid);
                    }
                    else if (prevAsteroid == abs(asteroid))
                    {
                        s.pop();
                    }
                }
            }
        }
        vector<int> res;
        while (!s.empty())
        {
            res.insert(res.begin(), s.top());
            s.pop();
        }
        return res;
    }
};
// @lc code=end
