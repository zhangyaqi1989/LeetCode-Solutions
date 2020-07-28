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
    private double max_avg;
    public double maximumAverageSubtree(TreeNode root) {
        max_avg = 0.0;
        postorder(root);
        return max_avg;
    }
    
    private double [] postorder(TreeNode node) {
        if(node != null) {
            double [] left = postorder(node.left);
            double [] right = postorder(node.right);
            double sum = left[0] + right[0] + node.val;
            double cnt = left[1] + right[1] + 1;
            max_avg = Math.max(max_avg, sum / cnt);
            return new double [] {sum, cnt};
        }
        return new double [] {0.0, 0};
    }
}
