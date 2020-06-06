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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> ans = new ArrayList<>();
        if (root == null) return ans;
        Queue<TreeNode> frontier = new LinkedList<>();
        frontier.add(root);
        while (!frontier.isEmpty()) {
            int sz = frontier.size();
            double s = 0;
            int cnt = 0;
            for(int i = 0; i < sz; ++i) {
                TreeNode node = frontier.poll();
                ++cnt;
                s += node.val;
                if (node.left != null) frontier.add(node.left);
                if (node.right != null) frontier.add(node.right);
            }
            ans.add(s / cnt);
        }
        return ans;
    }
}
