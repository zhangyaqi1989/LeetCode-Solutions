class Solution {
    public boolean leadsToDestination(int n, int[][] edges, int source, int destination) {
        List<Integer> [] graph = new ArrayList[n];
        for(int i = 0; i < n; ++i) graph[i] = new ArrayList<>();
        for(int [] e : edges) graph[e[0]].add(e[1]);
        boolean [] visited = new boolean[n];
        return dfs(source, destination, graph, visited);
    }
    
    public boolean dfs(int node, int destination, List<Integer> [] graph, boolean [] visited) {
        if (graph[node].isEmpty()) return node == destination;
        visited[node] = true;
        for(int nei : graph[node]) {
            if (visited[nei] || !dfs(nei, destination, graph, visited)) return false;
        }
        visited[node] = false;
        return true;
    }
}
