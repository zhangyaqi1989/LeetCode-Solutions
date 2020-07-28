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
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        Set<Integer> vals1 = new HashSet<>();
        Set<Integer> vals2 = new HashSet<>();
        Dfs(root1, vals1);
        Dfs(root2, vals2);
        for(int val : vals1) {
            if(vals2.contains(target - val)) {
                return true;
            }
        }
        return false;
    }
    
    private void Dfs(TreeNode node, Set<Integer> vals) {
        if(node != null) {
            vals.add(node.val);
            Dfs(node.left, vals);
            Dfs(node.right, vals);
        }
    }
}
