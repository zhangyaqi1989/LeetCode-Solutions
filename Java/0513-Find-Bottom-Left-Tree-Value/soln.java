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
    public int mx_level;
    public int ans;
    public int findBottomLeftValue(TreeNode root) {
        mx_level = 0;
        ans = root.val;
        preorder(root, 0);
        return ans;
    }
    
    public void preorder(TreeNode node, int level) {
        if (node != null) {
            if (level > mx_level) {
                mx_level = level;
                ans = node.val;
            }
            preorder(node.left, level + 1);
            preorder(node.right, level + 1);
        }
    }
}
