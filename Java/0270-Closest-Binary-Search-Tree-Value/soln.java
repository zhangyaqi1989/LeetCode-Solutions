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
    public int closestValue(TreeNode root, double target) {
        double mn = Double.MAX_VALUE;
        int ans = 0;
        while(root != null) {
            if (root.val == target) return root.val;
            else if (root.val < target) {
                if (target - root.val < mn) {
                    mn = target - root.val;
                    ans = root.val;
                }
                root = root.right;
            } else {
                if (root.val - target < mn) {
                    mn = root.val - target;
                    ans = root.val;
                }
                root = root.left;
            }
        }
        return ans;
    }
}
