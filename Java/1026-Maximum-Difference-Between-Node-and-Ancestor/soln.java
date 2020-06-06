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
    public int ans;
    public int maxAncestorDiff(TreeNode root) {
        ans = 0;
        dfs(root, Integer.MAX_VALUE, Integer.MIN_VALUE);
        return ans;
    }
    
    public void dfs(TreeNode node, int mn, int mx) {
        if (node == null) {
            ans = Math.max(ans, mx - mn);
        } else {
            dfs(node.left, Math.min(mn, node.val), Math.max(mx, node.val));
            dfs(node.right, Math.min(mn, node.val), Math.max(mx, node.val));
        }
    }
}
