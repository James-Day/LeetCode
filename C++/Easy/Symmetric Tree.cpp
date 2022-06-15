//Write a function to delete a node in a singly - linked list.You will not be 
//given access to the head of the list, instead you will be given access to 
//the node to be deleted directly.

//It is guaranteed that the node to be deleted is not a tail node in the list.


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
    bool isSymmetric(TreeNode* root) {

        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        else {
            return (left != nullptr && right != nullptr && left->val == right->val && 
                isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left));
        }
    }
};