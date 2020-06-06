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
    public boolean findTarget(TreeNode root, int k) {
        Set<Integer> needs = new HashSet<>();
        return preorder(root, k, needs);
    }
    
    private boolean preorder(TreeNode node, int target, Set<Integer> needs) {
        if (node != null) {
            if (needs.contains(node.val)) {
                return true;
            }
            needs.add(target - node.val);
            return preorder(node.left, target, needs) || preorder(node.right, target, needs);
        } else {
            return false;
        }
    }
}
