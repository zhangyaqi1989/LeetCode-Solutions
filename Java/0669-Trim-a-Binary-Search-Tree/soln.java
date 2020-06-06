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
    public TreeNode trimBST(TreeNode root, int L, int R) {
        if (L > R || root == null) return null;
        if (root.val >= L && root.val <= R) {
            root.left = trimBST(root.left, L, root.val);
            root.right = trimBST(root.right, root.val, R);
            return root;
        } else if (root.val < L) {
            return trimBST(root.right, L, R);
        } else {
            return trimBST(root.left, L, R);
        }
    }
}
