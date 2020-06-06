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
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        Map<TreeNode, List<TreeNode>> tree = new HashMap<>();
        traverse(root, tree);
        Queue<TreeNode[]> frontier = new LinkedList<>();
        frontier.offer(new TreeNode[] {target, null});
        while (K-- > 0 && !frontier.isEmpty()) {
            int sz = frontier.size();
            for(int i = 0; i < sz; ++i) {
                TreeNode [] p = frontier.poll();
                TreeNode node = p[0], parent = p[1];
                for(TreeNode nei : tree.getOrDefault(node, new ArrayList<>())) {
                    if (nei != parent) frontier.offer(new TreeNode[]{nei, node});
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        while (!frontier.isEmpty()) {
            ans.add(frontier.poll()[0].val);
        }
        return ans;
    }
    
    public void traverse(TreeNode node, Map<TreeNode, List<TreeNode>> tree) {
        if (node != null) {
            TreeNode [] children = new TreeNode []{node.left, node.right};
            for(TreeNode nei : children) {
                if (nei != null) {
                    tree.putIfAbsent(nei, new ArrayList<>());
                    tree.putIfAbsent(node, new ArrayList<>());
                    tree.get(nei).add(node);
                    tree.get(node).add(nei);
                    traverse(nei, tree);
                }
            }
        }
    }
}
