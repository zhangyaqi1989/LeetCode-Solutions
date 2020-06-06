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
    public boolean set;
    public String best;
    
    public String smallestFromLeaf(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        set = false;
        best = "";
        dfs(root, sb);
        return best;
    }
    
    public void dfs(TreeNode node, StringBuilder sb) {
        if (node != null) {
            sb.append((char) ('a' + node.val));
            if (node.left == null && node.right == null) {
                String cand = sb.toString();
                cand = new StringBuilder(cand).reverse().toString();
                if (!set || cand.compareTo(best) < 0) {
                    set = true;
                    best = cand;
                }
            }
            if(node.left != null) dfs(node.left, sb);
            if(node.right != null) dfs(node.right, sb);
            sb.setLength(sb.length() - 1);
        }
    }
}
