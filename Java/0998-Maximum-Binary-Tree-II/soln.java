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
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        TreeNode node = new TreeNode(val);
        if (root == null) return node;
        if (val > root.val) {
            node.left = root;
            return node;
        } else {
            TreeNode right = insertIntoMaxTree(root.right, val);
            root.right = right;
            return root;
        }
    }
}
