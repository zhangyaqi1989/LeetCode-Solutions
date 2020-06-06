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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> levels = new ArrayList<>();
        if(root == null) return levels;
        List<TreeNode> level = new ArrayList<>();
        level.add(root);
        while(!level.isEmpty()) {
            List<Integer> vals = new ArrayList<>();
            List<TreeNode> next_level = new ArrayList<>();
            for(TreeNode node : level) {
                vals.add(node.val);
                if (node.left != null) next_level.add(node.left);
                if (node.right != null) next_level.add(node.right);
            }
            level = next_level;
            levels.add(vals);
        }
        Collections.reverse(levels);
        return levels;
    }
}
