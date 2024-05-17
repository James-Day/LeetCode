class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode*& root, int target) {
        dfs(root->left, target);
        dfs(root->right, target);
        if (!root->left && !root->right && root->val == target) return nullptr; //leetcode does not let us delete the actual root node for some reason.
        return root;
    }
    void dfs(TreeNode*& root, int target) {
        if (!root) {
            return;
        }
        dfs(root->left, target);
        dfs(root->right, target);
        if (!root->left && !root->right && root->val == target) {
            delete root;
            root = nullptr;
        }
        return;
    }
};