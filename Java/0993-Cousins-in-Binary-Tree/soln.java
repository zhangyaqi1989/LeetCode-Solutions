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
    TreeMap<Integer, Integer> parents;
    TreeMap<Integer, Integer> depths;

    public boolean isCousins(TreeNode root, int x, int y) {
        parents = new TreeMap<Integer, Integer>();
        depths = new TreeMap<Integer, Integer>();
        traverse(root, -1, 0);
        return parents.get(x) != parents.get(y) && depths.get(x) == depths.get(y);
    }

    public void traverse(TreeNode node, int parent, int depth) {
        if (node != null) {
            // System.out.println(node);
            this.parents.put(node.val, parent);
            this.depths.put(node.val, depth);
            traverse(node.left, node.val, depth + 1);
            traverse(node.right, node.val, depth + 1);
        }
    }
}
