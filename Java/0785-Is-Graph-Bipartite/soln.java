class Solution {
    public boolean isBipartite(int[][] graph) {
        final int N = graph.length;
        int [] colors = new int [N];
        for(int i = 0; i < N; ++i) {
            if (colors[i] == 0) {
                colors[i] = 1;
                if (!dfs(i, graph, colors)) return false;
            } 
        }
        return true;
    }
    
    private boolean dfs(int u, int[][] graph, int [] colors) {
        for(int v : graph[u]) {
            if (colors[v] == colors[u]) return false;
            else if (colors[v] == 0) {
                colors[v] = -colors[u];
                if(!dfs(v, graph, colors)) return false;
            }
        }
        return true;
    }
}
