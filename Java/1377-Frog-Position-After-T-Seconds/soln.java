class Solution {
    private double prob;
    public double frogPosition(int n, int[][] edges, int t, int target) {
        List<Integer> [] graph = new ArrayList[n + 1];
        for(int i = 0; i < n + 1; ++i) graph[i] = new ArrayList<>();
        for(int [] edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].add(v);
            graph[v].add(u);
        }
        prob = 0.0;
        boolean [] visited = new boolean [n + 1];
        dfs(graph, t, target, 1, 1.0, visited);
        return prob;
    }
    
    private void dfs(List<Integer> [] graph, int t, int target, int node, double cur_prob, boolean [] visited) {
        if (t < 0) return;
        if (t == 0 && node == target) prob += cur_prob;
        visited[node] = true;
        List<Integer> cands = new ArrayList<>();
        for(int nei : graph[node]) {
            if (!visited[nei]) cands.add(nei);
        }
        if (cands.isEmpty()) {
            if (node == target && t != 0) prob += cur_prob;
        } else {
            double new_prob = cur_prob / cands.size();
            for(int cand : cands) {
                dfs(graph, t - 1, target, cand, new_prob, visited);
            }
        }
        visited[node] = false;
    }
}
