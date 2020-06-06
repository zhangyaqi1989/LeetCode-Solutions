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
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        boolean delete_root = postorder(root, target, null, true);
        return delete_root ? null : root;
    }
    
    // true means not exist or deleted
    private boolean postorder(TreeNode node, int target, TreeNode parent, boolean is_left) {
        if (node != null) {
            boolean ld = postorder(node.left, target, node, true);
            boolean rd = postorder(node.right, target, node, false);
            if (ld && rd && node.val == target) {
                if (parent != null) {
                    if (is_left) parent.left = null;
                    else parent.right = null;
                }
                return true;
            }
            return false;
        }
        return true;
    }
}
