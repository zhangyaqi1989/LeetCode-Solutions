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
    public int sumEvenGrandparent(TreeNode root) {
        ans = 0;
        dfs(root, null, null);
        return ans;
    }
    
    public void dfs(TreeNode node, TreeNode parent, TreeNode grad) {
        if (node != null) {
            if (grad != null && grad.val % 2 == 0) {
                ans += node.val;
            }
            dfs(node.left, node, parent);
            dfs(node.right, node, parent);
        }
    }
}
