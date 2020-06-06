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
    private int ans;
    public int longestUnivaluePath(TreeNode root) {
        // at every node, needs to know the path
        ans = 0;
        postOrder(root);
        return ans == 0 ? 0 : ans - 1;
    }
    
    private int [] postOrder(TreeNode node) {
        if (node == null) return new int[] {0, 0};
        int [] l = postOrder(node.left);
        int [] r = postOrder(node.right);
        int l_mx = 1, r_mx = 1;
        if(node.left != null && node.left.val == node.val) {
            l_mx += Math.max(l[0], l[1]);
        }
        if(node.right != null && node.right.val == node.val) {
            r_mx += Math.max(r[0], r[1]);
        }
        ans = Math.max(ans, l_mx + r_mx - 1);
        return new int [] {l_mx, r_mx};
    }
}
