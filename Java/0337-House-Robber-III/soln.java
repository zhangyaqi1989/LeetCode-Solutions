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
    public int rob(TreeNode root) {
        int[] ans = helper(root);
        return Math.max(ans[0], ans[1]);
    }
    
    public int[] helper(TreeNode node) {
        if (node == null) return new int[]{0, 0};
        int[] left = helper(node.left);
        int[] right = helper(node.right);
        int rob = node.val + left[1] + right[1];
        int not_rob = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        return new int[] {rob, not_rob};
    }
}
