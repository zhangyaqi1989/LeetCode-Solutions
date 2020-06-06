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
    public int getMinimumDifference(TreeNode root) {
        pre = -1;
        ans = Integer.MAX_VALUE;
        inorder(root);
        return ans;
    }
    
    public void inorder(TreeNode node) {
        if (node != null) {
            inorder(node.left);
            if (pre != -1) ans = Math.min(node.val - pre, ans);
            pre = node.val;
            inorder(node.right);
        }
    }
    
    private int pre;
    private int ans;
}
