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
    public int sum;
    public int sumOfLeftLeaves(TreeNode root) {
        sum = 0;
        dfs(root, false);
        return sum;
    }
    
    public void dfs(TreeNode node, boolean isLeft) {
        if (node != null) {
            if (node.left == null && node.right == null) {
                if (isLeft) sum += node.val;
            }
            dfs(node.left, true);
            dfs(node.right, false);
        }
    }
}
