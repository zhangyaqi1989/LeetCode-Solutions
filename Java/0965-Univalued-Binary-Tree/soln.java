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
    public boolean isUnivalTree(TreeNode root) {
        return dfs(root, root.val);
    }
    
    public boolean dfs(TreeNode node, int val) {
        if (node == null) return true;
        else return node.val == val && dfs(node.left, val) && dfs(node.right, val);
    }
}
