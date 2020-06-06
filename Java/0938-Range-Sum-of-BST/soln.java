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
    public int rangeSumBST(TreeNode root, int L, int R) {
        if (root == null) return 0;
        if (root.val < L) return rangeSumBST(root.right, L, R);
        else if (root.val > R) return rangeSumBST(root.left, L, R);
        else {
            return root.val + rangeSumBST(root.left, L, root.val - 1) + rangeSumBST(root.right, root.val + 1, R);
        }
    }
}
