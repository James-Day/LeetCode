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