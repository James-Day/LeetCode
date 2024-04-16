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

/* O(N) runtime, O(N) space (cause of recursion)*/
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (!root) return nullptr;
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            root = newRoot;
        }
        if (depth == 2) {
            addChildren(root, val);
            return root;
        }
        addOneRow(root->left, val, depth - 1);
        addOneRow(root->right, val, depth - 1);
        return root;
    }

    void addChildren(TreeNode* root, int val) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = new TreeNode(val);
        root->right = new TreeNode(val);
        root->left->left = left;
        root->right->right = right;
    }
};