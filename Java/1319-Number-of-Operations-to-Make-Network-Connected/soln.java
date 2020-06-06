class Solution {
    public int makeConnected(int n, int[][] connections) {
        int m = connections.length;
        if (m < n - 1) return -1;
        List<Integer> [] graph = new ArrayList[n];
        for(int i = 0; i < n; ++i) graph[i] = new ArrayList<>();
        for(int [] connect : connections) {
            int u = connect[0], v = connect[1];
            graph[u].add(v);
            graph[v].add(u);
        }
        boolean [] visited = new boolean[n];
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++cnt;
                Dfs(graph, i, visited);
            }
        }
        return cnt - 1;
    }
    private void Dfs(List<Integer>[] graph, int u, boolean [] visited) {
        visited[u] = true;
        for(int v : graph[u]) {
            if (!visited[v]) {
                Dfs(graph, v, visited);
            }
        }
    }
}
