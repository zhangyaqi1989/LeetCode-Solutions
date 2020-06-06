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
        if(root == null) return new TreeNode(val);
        if(root.val < val) {
            TreeNode new_root = new TreeNode(val);
            new_root.left = root;
            return new_root;
        } else {
            root.right = insertIntoMaxTree(root.right, val);
            return root;
        }
    }
}
