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
    public int deepestLeavesSum(TreeNode root) {
        List<TreeNode> frontier = new ArrayList<>();
        frontier.add(root);
        int ans = 0;
        while(!frontier.isEmpty()) {
            List<TreeNode> next_level = new ArrayList<>();
            ans = 0;
            for(TreeNode node : frontier) {
                ans += node.val;
                if (node.left != null) next_level.add(node.left);
                if (node.right != null) next_level.add(node.right);
            }
            frontier = next_level;
        }
        return ans;
    }
}
