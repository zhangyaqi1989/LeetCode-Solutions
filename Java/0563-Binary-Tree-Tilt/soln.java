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
    public int result = 0;
    public int findTilt(TreeNode root) {
        postOrder(root);
        return result;
    }
    
    public int postOrder(TreeNode node) {
        if (node == null) return 0;
        int l = postOrder(node.left);
        int r = postOrder(node.right);
        result += Math.abs(l - r);
        return node.val + l + r;
    }
}
