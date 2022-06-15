package easy;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class MaximumDepthofBinaryTree {

    public int maxDepth(TreeNode root) {
      if(root == null) return 0;
        int left = maxDepth(root.left);
        int right = maxDepth(root.right);
        
        return Math.max(left, right)+1;
    }
}

/* 
class PastSolution { 
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if (l>r){
            return l+1;
        }
        else{
            return r+1;
        }
    }
};
 */