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
// could also do this with a global vector, but I like pass by reference and a seperate function better.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
    void traverse(TreeNode* root, vector<int>& inOrder) {
        if (!root) return;
        traverse(root->left, inOrder);
        inOrder.push_back(root->val);
        traverse(root->right, inOrder);
    }
};