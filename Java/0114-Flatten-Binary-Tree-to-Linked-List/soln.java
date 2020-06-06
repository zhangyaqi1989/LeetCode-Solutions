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
    public TreeNode suc;
    public void flatten(TreeNode root) {
        suc = null;
        post(root);
    }
    
    public void post(TreeNode node) {
        if (node != null) {
            post(node.right);
            post(node.left);
            node.right = suc;
            node.left = null;
            suc = node;
        }
    }
}
