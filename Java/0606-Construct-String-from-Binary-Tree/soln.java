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
    public String tree2str(TreeNode t) {
        StringBuilder sb = new StringBuilder();
        preorder(sb, t);
        return sb.toString();
    }
    
    public void preorder(StringBuilder sb, TreeNode node) {
        if (node != null) {
            sb.append(Integer.toString(node.val));
            if (node.left != null || node.right != null) {
                sb.append("(");
                preorder(sb, node.left);
                sb.append(")");
                if (node.right != null) {
                    sb.append("(");
                    preorder(sb, node.right);
                    sb.append(")");
                }
            }
        }
    }
}
