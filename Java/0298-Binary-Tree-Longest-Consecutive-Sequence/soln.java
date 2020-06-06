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
    int ans;
    public int longestConsecutive(TreeNode root) {
        if (root == null) return 0;
        ans = 1;
        traverse(root, null, 1);
        return ans;
    }
    
    public void traverse(TreeNode node, TreeNode parent, int path) {
        if (node != null) {
            if (parent != null) {
                if (parent.val + 1 == node.val) {
                    ++path;
                    ans = Math.max(ans, path);
                } else {
                    path = 1;
                }

            }
            traverse(node.left, node, path);
            traverse(node.right, node, path);
        }
    }
}
