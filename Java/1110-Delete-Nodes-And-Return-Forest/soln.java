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
    public Set<Integer> deletes;
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        deletes = new HashSet<>();
        List<TreeNode> ans = new ArrayList<>();
        for(int num : to_delete) deletes.add(num);
        dfs(root, true, ans);
        return ans;
    }
    
    public TreeNode dfs(TreeNode node, boolean is_root, List<TreeNode> ans) {
        if (node == null) return null;
        boolean is_delete = deletes.contains(node.val);
        node.left = dfs(node.left, is_delete, ans);
        node.right = dfs(node.right, is_delete, ans);
        if (!is_delete && is_root) ans.add(node);
        return is_delete ? null : node;
    }
}
