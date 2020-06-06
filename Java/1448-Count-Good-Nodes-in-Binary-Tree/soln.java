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
    public int ans;
    public int goodNodes(TreeNode root) {
        ans = 0;
        dfs(root, -100000);
        return ans;
    }
    
    private void dfs(TreeNode node, int mx) {
        if(node != null) {
            if(node.val >= mx) ans += 1;
            mx = Math.max(mx, node.val);
            dfs(node.left, mx);
            dfs(node.right, mx);
        }
    }
}
