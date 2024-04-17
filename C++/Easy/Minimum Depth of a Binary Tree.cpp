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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        // could also specify the leaf case here by explicitly returning 1
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }

};
/* My initial solution
* 

    int minDepth(TreeNode* root) {
        int min = INT_MAX;
        helper(root, min, 1);
        return min == INT_MAX ? 0 : min;
    }
    void helper(TreeNode* root, int& minimum, int depth){
        if (!root) return;
        if(!root->left && !root->right){
            minimum = min(minimum, depth);
        }
        helper(root->left, minimum, depth + 1);
        helper(root->right, minimum, depth + 1);
    }
*/