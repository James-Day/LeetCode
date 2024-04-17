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
    bool isBalanced(TreeNode* root) {
        return root == nullptr ? true : height(root) != -1;
    }
    int height(TreeNode* root) {
        if (!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        if (l == -1 || r == -1) return -1; //once there is a height imbalance, return the way up the stack.
        if (abs(l - r) > 1) return -1;
        return max(l, r) + 1;
    }
};
/*
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        return dfs(root) != -1;
    }
    int dfs(TreeNode* root){
       if (root == nullptr){
           return 0;
       }

      int l = dfs(root->left);
      int r = dfs(root->right);
      
      if( l == -1 || r == -1){
          return -1;
      }

        if(abs(l - r) > 1){
            return -1;
      }
      return max(l,r) + 1;
    }
};
*/