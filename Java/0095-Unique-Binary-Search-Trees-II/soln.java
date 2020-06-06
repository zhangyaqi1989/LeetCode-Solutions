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
    public List<TreeNode> generateTrees(int n) {
        if (n <= 0) return new ArrayList<>();
        return build(1, n);
    }
    
    public List<TreeNode> build(int lo, int hi) {
        if (lo > hi) {
            List<TreeNode> ans = new ArrayList<>();
            ans.add(null);
            return ans;
        }
        List<TreeNode> ans = new ArrayList<>();
        for(int mid = lo; mid <= hi; ++mid) {
            for(TreeNode left : build(lo, mid - 1)) {
                for(TreeNode right : build(mid + 1, hi)) {
                    TreeNode root = new TreeNode(mid);
                    root.left = left;
                    root.right = right;
                    ans.add(root);
                }
            }
        }
        return ans;
    }
}
