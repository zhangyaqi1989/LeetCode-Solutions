/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import javafx.util.Pair; 
class Solution {
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        Pair<Integer, TreeNode> ans = helper(root);
        return ans.getValue();
    }
    
    public Pair<Integer, TreeNode> helper(TreeNode node) {
        if (node == null) return new Pair(0, null);
        Pair<Integer, TreeNode> l = helper(node.left), r = helper(node.right);
        if (l.getKey() == r.getKey()) {
            return new Pair(l.getKey() + 1, node);
        } else if (l.getKey() < r.getKey()) {
            return new Pair(r.getKey() + 1, r.getValue());
        } else {
            return new Pair(l.getKey() + 1, l.getValue());
        }
    }
}
