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
    public int cnt;
    public int pathSum(TreeNode root, int target) {
        Map<Integer, Integer> seen = new HashMap<>();
        cnt = 0;
        seen.put(0, 1);
        dfs(root, seen, target, 0);
        return cnt;
    }
    
    public void dfs(TreeNode node, Map<Integer, Integer> seen, int target, int acc) {
        if (node != null) {
            acc += node.val;
            if (seen.get(acc - target) != null) cnt += seen.get(acc - target);
            seen.put(acc, seen.getOrDefault(acc, 0) + 1);
            dfs(node.left, seen, target, acc);
            dfs(node.right, seen, target, acc);
            seen.put(acc, seen.get(acc) - 1);
        }
    }
}
