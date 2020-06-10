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
        Pair<Integer, TreeNode> ans = postorder(root);
        return ans.getValue();
    }
    
    public Pair<Integer, TreeNode> postorder(TreeNode root) {
        if (root == null) return new Pair(0, null);
        Pair<Integer, TreeNode> l = postorder(root.left), r = postorder(root.right);
        if (l.getKey() > r.getKey()) return new Pair(l.getKey() + 1, l.getValue());
        else if (r.getKey() > l.getKey()) return new Pair(r.getKey() + 1, r.getValue());
        return new Pair(l.getKey() + 1, root);
    }
}
