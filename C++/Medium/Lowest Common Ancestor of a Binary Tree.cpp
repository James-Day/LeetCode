
 // Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* lca = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        numDescendantsFound(root, p, q);
        return lca;
    }
    int numDescendantsFound(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return 0;
        }

        int l = numDescendantsFound(root->left, p, q);
        int r = numDescendantsFound(root->right, p, q);

        if (l == -1 || r == -1) {
            return -1;
        }
        bool found = (root == p) || (root == q);
        if (l + r + found == 2) {
            lca = root;
            return -1;
        }
        return l + r + found;

    }
};