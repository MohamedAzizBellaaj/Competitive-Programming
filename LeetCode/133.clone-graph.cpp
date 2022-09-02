/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    unordered_map<Node *, Node *> oldToNew;
    Node *dfs(Node *node)
    {
        if (oldToNew.count(node) != 0)
        {
            return oldToNew[node];
        }
        Node *copy = new Node(node->val);
        oldToNew[node] = copy;
        for (auto &neighbor : node->neighbors)
        {
            copy->neighbors.push_back(dfs(neighbor));
        }
        return copy;
    }
    Node *cloneGraph(Node *node)
    {
        return node ? dfs(node) : nullptr;
    }
};
// @lc code=end
