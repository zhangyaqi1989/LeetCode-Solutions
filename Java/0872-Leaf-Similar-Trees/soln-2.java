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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> vals1 = new ArrayList<>();
        List<Integer> vals2 = new ArrayList<>();
        inorder(root1, vals1);
        inorder(root2, vals2);
        if(vals1.size() != vals2.size()) return false;
        int n = vals1.size();
        for(int i = 0; i < n; ++i) {
            if (vals1.get(i) != vals2.get(i)) return false;
        }
        return true;
    }
    
    private void inorder(TreeNode node, List<Integer> vals) {
        if (node != null) {
            inorder(node.left, vals);
            if(node.left == null && node.right == null) {
                vals.add(node.val);
            }
            inorder(node.right, vals);
        }
    }
}
