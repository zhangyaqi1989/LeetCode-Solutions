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
    public int cnt;
    public int countUnivalSubtrees(TreeNode root) {
        cnt = 0;
        helper(root);
        return cnt;
    }
    
    public int [] helper(TreeNode node) {
        if (node == null) return new int[] {Integer.MAX_VALUE, Integer.MIN_VALUE};
        else {
            int [] lp = helper(node.left);
            int [] rp = helper(node.right);
            int mn = Math.min(lp[0], rp[0]), mx = Math.max(lp[1], rp[1]);
            mn = Math.min(node.val, mn);
            mx = Math.max(node.val, mx);
            if (mx == mn) ++cnt;
            return new int[] {mn, mx};
        }
    }
}
