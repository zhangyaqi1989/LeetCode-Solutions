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
    public List<TreeNode> allPossibleFBT(int N) {
        List<TreeNode> ans = new ArrayList<>();
        if (N == 1) ans.add(new TreeNode(0));
        else {
            for(int left = 1; left < N - 1; left += 2) {
                int right = N - left - 1;
                List<TreeNode> left_nodes = allPossibleFBT(left);
                List<TreeNode> right_nodes = allPossibleFBT(right);
                for(TreeNode left_node : left_nodes)
                    for(TreeNode right_node : right_nodes) {
                        TreeNode root = new TreeNode(0);
                        root.left = left_node;
                        root.right = right_node;
                        ans.add(root);
                    }
            }
        }
        return ans;
    }
}
