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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) return ans;
        Queue<TreeNode> frontier = new LinkedList<>();
        frontier.offer(root);
        while (!frontier.isEmpty()) {
            int sz = frontier.size();
            int mx = Integer.MIN_VALUE;
            for(int i = 0; i < sz; ++i) {
                TreeNode node = frontier.poll();
                mx = Math.max(mx, node.val);
                if (node.left != null) frontier.offer(node.left);
                if (node.right != null) frontier.offer(node.right);
            }
            ans.add(mx);
        }
        return ans;
    }
}
