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
    private int sum;
    public int sumNumbers(TreeNode root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }
    
    private void dfs(TreeNode node, int path) {
        if(node != null) {
            if(node.left == null && node.right == null) {
                sum += path * 10 + node.val;
            }
            dfs(node.left, path * 10 + node.val);
            dfs(node.right, path * 10 + node.val);
        }
    }
}
