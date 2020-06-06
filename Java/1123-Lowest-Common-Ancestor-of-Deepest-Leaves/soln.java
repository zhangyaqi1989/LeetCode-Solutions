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
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        depths = new HashMap<>();
        getDepth(root);
        return helper(root);
    }
    
    public TreeNode helper(TreeNode node) {
        if (node == null) return null;
        int l = depths.get(node.left);
        int r = depths.get(node.right);
        if (l == r) return node;
        else if (l > r) return helper(node.left);
        else return helper(node.right);
    }
    
    public int getDepth(TreeNode node) {
        int ans = 0;
        if (node != null) {
            ans = Math.max(getDepth(node.left), getDepth(node.right)) + 1;
        } 
        depths.put(node, ans);
        return ans;
        
    }
    
    public Map<TreeNode, Integer> depths;
}
