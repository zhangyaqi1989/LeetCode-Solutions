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
    public int pre;
    public int ans;
    public int minDiffInBST(TreeNode root) {
        pre = ans = Integer.MAX_VALUE;
        inorder(root);
        return ans;
    }
    
    public void inorder(TreeNode node) {
        if (node != null) {
            inorder(node.left);
            if (pre != Integer.MAX_VALUE && node.val - pre < ans) {
                ans = node.val - pre;
            }
            pre = node.val;
            inorder(node.right);
        }
    }
}
