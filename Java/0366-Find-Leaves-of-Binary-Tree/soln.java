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
    public List<List<Integer>> findLeaves(TreeNode root) {
        Map<Integer, List<Integer>> levels = new HashMap<>();
        List<List<Integer>> ans = new ArrayList<>();
        post(root, levels);
        for(int level = 1; ; ++level) {
            if (!levels.containsKey(level)) break;
            ans.add(levels.get(level));
        }
        return ans;
    }
    
    public int post(TreeNode node, Map<Integer, List<Integer>> levels) {
        if (node == null) return 0;
        int l = post(node.left, levels);
        int r = post(node.right, levels);
        int ans = Math.max(l, r) + 1;
        if (!levels.containsKey(ans)) levels.put(ans, new ArrayList<Integer>());
        levels.get(ans).add(node.val);
        return ans;
    }
}
