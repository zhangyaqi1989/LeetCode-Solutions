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
    public TreeNode bstFromPreorder(int[] preorder) {
        int n = preorder.length;
        return helper(preorder, 0, n);
    }
    public TreeNode helper(int[] preorder, int lo, int hi) {
        if (lo >= hi) return null;
        int root_val = preorder[lo];
        int idx = lo + 1;
        while (idx < hi) {
            if (preorder[idx] > root_val) break;
            ++idx;
        }
        TreeNode root = new TreeNode(root_val);
        root.left = helper(preorder, lo + 1, idx);
        root.right = helper(preorder, idx, hi);
        return root;
    }
}
