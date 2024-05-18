class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    int dfs(TreeNode* root, int& moves) {
        if (!root) return 0;

        int left = dfs(root->left, moves);
        int right = dfs(root->right, moves);
        moves += abs(left) + abs(right);
        return root->val + left + right - 1;
    }
};