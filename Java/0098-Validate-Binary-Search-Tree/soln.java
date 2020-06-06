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
    TreeNode prev;
    public boolean isValidBST(TreeNode root) {
        prev = null;
        return valid(root);
    }
    
    public boolean valid(TreeNode node) {
        if (node != null) {
            if (!valid(node.left)) return false;
            if (prev != null && prev.val >= node.val) return false;
            prev = node;
            return valid(node.right);
        }
        return true;
    }
}
