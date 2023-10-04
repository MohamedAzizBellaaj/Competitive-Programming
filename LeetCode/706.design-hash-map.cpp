/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap
{
private:
    unordered_map<int, int> m;

public:
    void put(int key, int value)
    {
        m[key] = value;
    }

    int get(int key)
    {
        return m.find(key) != m.end() ? m[key] : -1;
    }

    void remove(int key)
    {
        m.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
