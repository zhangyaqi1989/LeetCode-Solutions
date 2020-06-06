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
    public int ans;
    public int longestConsecutive(TreeNode root) {
        ans = 0;
        postorder(root);
        return ans;
    }
    
    public int [] postorder(TreeNode node) {
        if (node != null) {
            int [] l = postorder(node.left);
            int [] r = postorder(node.right);
            int l_inc = l[0], l_dec = l[1], r_inc = r[0], r_dec = r[1];
            int inc = 1, dec = 1;
            if (node.left != null) {
                if (node.val + 1 == node.left.val) inc = Math.max(inc, l_inc + 1);
                else if (node.val - 1 == node.left.val) dec = Math.max(dec, l_dec + 1);
            }
            if (node.right != null) {
                if (node.val + 1 == node.right.val) inc = Math.max(inc, r_inc + 1);
                else if (node.val - 1 == node.right.val) dec = Math.max(dec, r_dec + 1);
            }
            ans = Math.max(ans, inc + dec - 1);
            return new int[] {inc, dec};
        } else {
            return new int[] {0, 0};
        }
    }
}
