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
 //Must go right to left because post order's last element is the root, and it's second to last is the right child unless there is no right child, then it's the left child
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }
        return helper(inorder, postorder, indexMap, 0, postorder.size() - 1);
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& indexMap, int left, int right) {
        if (left > right) return nullptr;
        TreeNode* root = new TreeNode(postorder.back());
        postorder.pop_back();

        int index = indexMap[root->val];
        root->right = helper(inorder, postorder, indexMap, index + 1, right);
        root->left = helper(inorder, postorder, indexMap, left, index - 1);
        return root;
    }
};