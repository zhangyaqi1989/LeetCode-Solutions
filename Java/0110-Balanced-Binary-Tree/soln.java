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
    public boolean ans;
    public boolean isBalanced(TreeNode root) {
        ans = true;
        post(root);
        return ans;
    }
    
    public int post(TreeNode root) {
        if (!ans) return 0;
        if (root == null) return 0;
        int l = post(root.left);
        int r = post(root.right);
        if (Math.abs(l - r) > 1) ans = false;
        return Math.max(l, r) + 1;
    }
}
