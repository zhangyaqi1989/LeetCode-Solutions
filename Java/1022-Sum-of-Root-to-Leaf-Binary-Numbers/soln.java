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
    public long mod = 1000000007;
    public long ans = 0;
    public int sumRootToLeaf(TreeNode root) {
        helper(root, 0);
        return (int) ans;
    }
    
    public void helper(TreeNode node, long path) {
        if (node != null) {
            path = (path * 2 + node.val) % mod;
            if (node.left == null && node.right == null) {
                ans = (ans + path) % mod;
            }
            helper(node.left, path);
            helper(node.right, path);
        } 
    }
}
