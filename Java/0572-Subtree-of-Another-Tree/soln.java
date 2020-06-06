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
    public boolean isSubtree(TreeNode s, TreeNode t) {
        String sstr = encode(s);
        String tstr = encode(t);
        return sstr.indexOf(tstr) != -1;
    }
    
    public String encode(TreeNode node) {
        if (node == null) return "";
        String l = encode(node.left);
        String r = encode(node.right);
        return "^" + Integer.toString(node.val) + l + r + "$";
    }
}
