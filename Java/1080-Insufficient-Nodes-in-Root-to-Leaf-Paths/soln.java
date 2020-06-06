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
    public TreeNode sufficientSubset(TreeNode root, int limit) {
        return postOrder(root, limit).getKey();
    }
    
    public Pair<TreeNode, Integer> postOrder(TreeNode node, int limit) {
        if (node != null) {
            Pair<TreeNode, Integer> lp = postOrder(node.left, limit - node.val);
            Pair<TreeNode, Integer> rp = postOrder(node.right, limit - node.val);
            node.left = lp.getKey();
            node.right = rp.getKey();
            int mx = Math.max(lp.getValue(), rp.getValue()) + node.val;
            if (mx >= limit) {
                return new Pair(node, mx);
            } else {
                return new Pair(null, mx);
            }
        } else {
            return new Pair(null, 0);
        }
    }
}
