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
    public int countNodes(TreeNode root) {
        if(root == null) return 0;
        int l = computeHeight(root.left);
        int r = computeHeight(root.right);
        if(l > r) return (1 << r) + countNodes(root.left);
        else return (1 << l) + countNodes(root.right);
    }
    
    private int computeHeight(TreeNode node) {
        if (node == null) return 0;
        return 1 + Math.max(computeHeight(node.left), computeHeight(node.right));
    }
}
