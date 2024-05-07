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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;
        return dfs(node, map);
    }
    Node* dfs(Node* node, unordered_map<Node*, Node*>& map) {
        if (node == nullptr) return nullptr;
        if (map.contains(node)) {
            return map[node];
        }
        map[node] = new Node(node->val);
        for (Node* cur : node->neighbors) {
            Node* copy = dfs(cur, map);
            map[node]->neighbors.push_back(copy);
        }
        return map[node];
    }
};