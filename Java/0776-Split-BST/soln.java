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
    public TreeNode[] splitBST(TreeNode root, int V) {
        if (root == null) return new TreeNode[] {null, null};
        else {
            TreeNode[] ans = new TreeNode[2];
            if (root.val == V) {
                ans[1] = root.right;
                root.right = null;
                ans[0] = root;
            } else if (root.val < V) {
                TreeNode[] lr = splitBST(root.right, V);
                ans[1] = lr[1];
                root.right = lr[0];
                ans[0] = root;
            } else {
                TreeNode[] lr = splitBST(root.left, V);
                ans[0] = lr[0];
                root.left = lr[1];
                ans[1] = root;
            }
            return ans;
        }
        
    }
}
