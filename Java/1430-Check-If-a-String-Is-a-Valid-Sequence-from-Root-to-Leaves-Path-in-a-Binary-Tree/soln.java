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
    public boolean isValidSequence(TreeNode root, int[] arr) {
        return dfs(root, arr, 0);
    }
    
    private boolean dfs(TreeNode node, int [] arr, int idx) {
        if(idx == arr.length - 1) return node != null && node.val == arr[arr.length - 1] && node.left == null && node.right == null;
        return node != null && node.val == arr[idx] && (dfs(node.left, arr, idx + 1) || dfs(node.right, arr, idx + 1));
    }
}
