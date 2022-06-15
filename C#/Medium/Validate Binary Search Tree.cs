/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

public class Solution
{
    public bool IsValidBST(TreeNode root)
    {
        List<int> inOrder = new List<int>();
        isValidBSTHelper(root, inOrder);

        for (int i = 0; i < inOrder.Count - 1; i++)
        {
            if (inOrder[i] >= inOrder[i + 1])
            {
                return false;
            }
        }
        return true;
    }
    private void isValidBSTHelper(TreeNode root, List<int> inOrder)
    {
        if (root == null)
        {
            return;
        }

        isValidBSTHelper(root.left, inOrder);
        inOrder.Add(root.val);
        isValidBSTHelper(root.right, inOrder);
    }
}

/* Past solution
public class PastSolution
{
    public bool IsValidBST(TreeNode root)
    {
        return validate(root, -Int32.MaxValue, -Int32.MaxValue);
    }
    private bool validate(TreeNode cur, int high, int low)
    {
        if (cur == null)
        {
            return true;
        }
        if ((low != -Int32.MaxValue && cur.val <= low) || (high != -Int32.MaxValue && cur.val >= high))
        {
            return false;
        }
        return validate(cur.right, high, cur.val) && validate(cur.left, cur.val, low);
    }
}
*/