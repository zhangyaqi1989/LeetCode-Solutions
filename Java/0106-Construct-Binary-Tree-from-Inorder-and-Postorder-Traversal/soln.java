/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = inorder.length;
        return helper(inorder, 0, n, postorder, 0, n);
    }
    
    public TreeNode helper(int [] inorder, int i_lo, int i_hi, int [] postorder, int p_lo, int p_hi) {
        if (i_hi <= i_lo) return null;
        int root_val = postorder[p_hi - 1];
        TreeNode root = new TreeNode(root_val);
        int idx = i_lo;
        for(; idx < i_hi; ++idx) {
            if (inorder[idx] == root_val) break;
        }
        root.left = helper(inorder, i_lo, idx, postorder, p_lo, p_lo + idx - i_lo);
        root.right = helper(inorder, idx + 1, i_hi, postorder, p_lo + idx - i_lo, p_hi - 1);
        return root;
    }
}
