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
    public TreeNode pruneTree(TreeNode root) {
        int ans = helper(root);
        return ans == 0 ? null : root;
    }
    
    public int helper(TreeNode node) {
        if (node == null) return 0;
        int left = helper(node.left);
        int right = helper(node.right);
        if (left == 0) node.left = null;
        if (right == 0) node.right = null;
        return node.val + left + right;
    }
}
