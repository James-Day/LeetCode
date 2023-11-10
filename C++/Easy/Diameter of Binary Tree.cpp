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

#include <algorithm>
using namespace std;

class Solution {
public:
    int longestDiameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return longestDiameter;
    }

    int helper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int l = helper(root->left);
        int r = helper(root->right);

        if (longestDiameter < (l + r)) {
            longestDiameter = l + r;
        }
        return max(l + 1, r + 1);
    }

};