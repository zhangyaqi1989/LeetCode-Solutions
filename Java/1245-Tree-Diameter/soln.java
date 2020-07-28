class Solution {
    public int furthest_node;
    public int max_distance;

    public int treeDiameter(int[][] edges) {
        int n = edges.length + 1;
        ArrayList<Integer> [] tree = new ArrayList[n];
        for(int i = 0; i < n; ++i) tree[i] = new ArrayList<>();
        for(int [] edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].add(v);
            tree[v].add(u);
        }
        furthest_node = -1;
        max_distance = 0;
        dfs(tree, 0, -1, 0);
        max_distance = 0;
        dfs(tree, furthest_node, -1, 0);
        return max_distance;
    }
    
    private void dfs(ArrayList<Integer> [] tree, int node, int parent, int distance) {
        if(distance > max_distance) {
            max_distance = distance;
            furthest_node = node;
        }
        for(int nei : tree[node]) {
            if(nei != parent) {
                dfs(tree, nei, node, distance + 1);
            }
        }
    }
}
