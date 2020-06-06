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
    Map<String, ArrayList<TreeNode>> subs;
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        subs = new HashMap<>();
        List<TreeNode> ans = new ArrayList<>();
        helper(root);
        for(List<TreeNode> lst : subs.values()) {
            if (lst.size() > 1) ans.add(lst.get(0));
        }
        return ans;
    }
    
    public String helper(TreeNode node) {
        if (node == null) return "#";
        String ans = Integer.toString(node.val) + helper(node.left) + helper(node.right);
        if (!subs.containsKey(ans)) subs.put(ans, new ArrayList<>());
        subs.get(ans).add(node);
        return ans;
    }
}
