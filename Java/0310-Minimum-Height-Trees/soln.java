class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        int[] degrees = new int[n];
        ArrayList<Integer>[] graph = new ArrayList[n];
        for(int i = 0; i < n; ++i) graph[i] = new ArrayList<>();
        for (int[] row : edges) {
            int a = row[0], b = row[1];
            ++degrees[a];
            ++degrees[b];
            graph[a].add(b);
            graph[b].add(a);
        }
        Set<Integer> nodes = new HashSet<Integer>();
        for(int i = 0; i < n; ++i) nodes.add(i);
        while (nodes.size() > 2) {
            Set<Integer> leafs = new HashSet<Integer>();
            for(int i = 0; i < n; ++i) {
                if (degrees[i] == 1) leafs.add(i);
            }
            for(int leaf : leafs) {
                degrees[leaf] = 0;
                nodes.remove(leaf);
                for(int nei : graph[leaf]) {
                    --degrees[nei];
                }
            }
        }
        List<Integer> ans = new ArrayList<Integer>();
        for(int node : nodes)
            ans.add(node);
        return ans;
    }
}
