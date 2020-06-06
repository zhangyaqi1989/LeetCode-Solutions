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
    private int min_depth;
    public int minDepth(TreeNode root) {
        min_depth = -1;
        dfs(root, 1);
        return min_depth == -1 ? 0 : min_depth;
    }
    
    private void dfs(TreeNode node, int depth) {
        if(node != null) {
            if(node.left == null && node.right == null) {
                if(min_depth == -1 || depth < min_depth) min_depth = depth;
            }
            dfs(node.left, depth + 1);
            dfs(node.right, depth + 1);
        }
    }
}
