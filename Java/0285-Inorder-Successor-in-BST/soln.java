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
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        TreeNode suc = null;
        while (root != null) {
            if (p.val >= root.val) {
                root = root.right;
            } else {
                suc = root;
                root = root.left;
            }
        }
        return suc;
    }
}
