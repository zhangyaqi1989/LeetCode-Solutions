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
    public int findSecondMinimumValue(TreeNode root) {
        int[] first = {Integer.MAX_VALUE};
        int[] second = {Integer.MAX_VALUE};
        traverse(root, first, second);
        return second[0] == Integer.MAX_VALUE ? -1 : second[0]; 
    }
    
    public void traverse(TreeNode node, int[] first, int[] second) {
        if (node != null) {
            if (node.val < first[0]) {
                first[0] = node.val;
            } else if (node.val != first[0] && node.val < second[0]) {
                second[0] = node.val;
            }
            traverse(node.left, first, second);
            traverse(node.right, first, second);
        }
    }
}
