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
    public int findClosestLeaf(TreeNode root, int k) {
        final int N = 1001;
        boolean [] leafs = new boolean[N];
        ArrayList<Integer>[] graph = new ArrayList[N];
        for(int i = 0; i < N; ++i) {
            graph[i] = new ArrayList<>();
            leafs[i] = false;
        }
        traverse(root, leafs, graph);
        Queue<Integer> frontier = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();
        frontier.add(k);
        visited.add(k);
        while(!frontier.isEmpty()) {
            int node = frontier.poll();
            if (leafs[node]) return node;
            for(int nei : graph[node]) {
                if (!visited.contains(nei)) {
                    frontier.add(nei);
                    visited.add(nei);
                }
            }
        }
        return 0;
    }
    
    public void traverse(TreeNode node, boolean [] leafs, ArrayList<Integer> [] graph) {
       if (node != null) {
           if (node.left == null && node.right == null) leafs[node.val] = true;
           if(node.left != null) {
               graph[node.val].add(node.left.val);
               graph[node.left.val].add(node.val);
               traverse(node.left, leafs, graph);
           }
           if (node.right != null) {
               graph[node.val].add(node.right.val);
               graph[node.right.val].add(node.val);
               traverse(node.right, leafs, graph);
           }
       } 
    }
}
