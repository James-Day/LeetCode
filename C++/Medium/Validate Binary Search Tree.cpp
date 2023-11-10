#include <vector>
using namespace std;

 // Definition for a binary tree node.
    struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> nums;

        inOrder(root, nums);

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
        }
        return true;
    }

    void inOrder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }

        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);

    }
};

/* DFS
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return BSTHelper(root, LONG_MAX, LONG_MIN);
    }

   bool BSTHelper(TreeNode* root, long max, long min){
       if (root == nullptr){
           return true;
       }

       if(root->val >= max || root->val <= min){
           return false;
       }

       return (BSTHelper(root->left, root->val, min) && BSTHelper(root->right, max, root->val));
   }
};

*/

/*
//bad implementation for fun
class Solution {
public:
    bool isValidBST(TreeNode* root) {
       return isValid(root, INT_MAX, INT_MIN, false, false);
    }
    bool isValid(TreeNode* root, int high, int low, bool highUpdated, bool lowUpdated){

        if(root == nullptr){ return true;}

        if((root->left == nullptr && root->right != nullptr) && (high != INT_MAX && low != INT_MIN)){
            if((high > root->val && low < root->val) && isValid(root->right, high, root->val, highUpdated, true)){
                return true;
            }
            return false;
        }
        if((root->right == nullptr && root->left != nullptr) && (low != INT_MIN && high != INT_MAX)){
            if((low < root->val) &&  (high > root->val && isValid(root->left, root->val, low, true, lowUpdated))){
            return true;
            }
            return false;
        }
        if((low >= root->val && low != INT_MIN) || (high <= root-> val && high != INT_MAX)){
            return false;
        }
        if(((low == INT_MIN && lowUpdated) && root->val == low) || ((high == INT_MAX && highUpdated)) && root->val == high){
            return false;
       }
            if(isValid(root->left, root->val, low, true, lowUpdated) && isValid(root->right, high, root->val, highUpdated ,true)){
                return true;
            }
        return false;
    }
};


*/