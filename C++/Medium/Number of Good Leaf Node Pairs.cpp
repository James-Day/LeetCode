/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int pairs = 0;
        dfs(root, distance, pairs);
        return pairs;
    }
    vector<int> dfs(TreeNode* node, int& distance, int& pairs) {
        vector<int> all_dist;
        if (!node) return all_dist;
        if (!node->left && !node->right) {
            all_dist.push_back(1);
            return all_dist;
        }
        vector<int> left_distances = dfs(node->left, distance, pairs);
        vector<int> right_distances = dfs(node->right, distance, pairs);

        for (int i = 0; i < left_distances.size(); i++) {
            for (int j = 0; j < right_distances.size(); j++) {
                if (left_distances[i] + right_distances[j] <= distance) {
                    pairs++;
                }
            }
        }
        //all_dist.insert(all_dist.end(), left_distances.begin(), left_distances.end()); //slower cause a third iteration would be need for incrementing
        //all_dist.insert(all_dist.end(), right_distances.begin(), right_distances.end());
        for (int i = 0; i < left_distances.size(); i++) {
            all_dist.push_back(left_distances[i] + 1);
        }
        for (int i = 0; i < right_distances.size(); i++) {
            all_dist.push_back(right_distances[i] + 1);
        }
        return all_dist;
    }
};
// optimized space
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int pairs = 0;
        dfs(root, distance, pairs);
        return pairs;
    }
    unordered_map<int, int> dfs(TreeNode* node, int& distance, int& pairs) {
        unordered_map<int, int> all_dist; // likely much better if you use a vector of size distance + 1 instead.
        if (!node) return all_dist;
        if (!node->left && !node->right) {
            all_dist[1] = 1;
            return all_dist;
        }
        unordered_map<int, int> left_distances = dfs(node->left, distance, pairs);
        unordered_map<int, int> right_distances = dfs(node->right, distance, pairs);

        for (auto i = left_distances.begin(); i != left_distances.end(); i++) {
            for (auto j = right_distances.begin(); j != right_distances.end(); j++) {
                if (i->first + j->first <= distance) {
                    pairs += i->second * j->second;
                }
            }
        }
        for (auto i = left_distances.begin(); i != left_distances.end(); i++) {
            if (i->first + 1 <= distance) {
                all_dist[i->first + 1] += i->second;
            }
        }
        for (auto j = right_distances.begin(); j != right_distances.end(); j++) {
            if (j->first + 1 <= distance) {
                all_dist[j->first + 1] += j->second;
            }
        }
        return all_dist;
    }
};