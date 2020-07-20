/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> getLonelyNodes(TreeNode root) {
        List<Integer> lonely_vals = new ArrayList<>();
        Dfs(root, lonely_vals);
        return lonely_vals;
    }
    
    public void Dfs(TreeNode node, List<Integer> lonely_vals) {
        if(node != null) {
            if(node.left == null && node.right != null) {
                lonely_vals.add(node.right.val);
            }
            if(node.left != null && node.right == null) {
                lonely_vals.add(node.left.val);
            }
            Dfs(node.left, lonely_vals);
            Dfs(node.right, lonely_vals);
        }
    }
}
