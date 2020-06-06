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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;
        return build(preorder, 0, n, inorder, 0, n);
    }
    
    public TreeNode build(int [] preorder, int p_lo, int p_hi, int [] inorder, int i_lo, int i_hi) {
        if (p_hi <= p_lo) return null;
        int root_val = preorder[p_lo];
        TreeNode root =  new TreeNode(root_val);
        int idx = i_lo;
        for(; idx < i_hi; ++idx) {
            if (inorder[idx] == root_val) break;
        }
        int cnt = idx - i_lo;
        root.left = build(preorder, p_lo + 1, p_lo + 1 + cnt, inorder, i_lo, idx);
        root.right = build(preorder, p_lo + 1 + cnt, p_hi, inorder, idx + 1, i_hi);
        return root;
    }
}

