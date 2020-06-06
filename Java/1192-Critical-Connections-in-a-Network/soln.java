class Solution {
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        time = 0;
        lows = new int[n];
        times = new int[n];
        Arrays.fill(lows, INF);
        Arrays.fill(times, INF);
        ArrayList<Integer> [] graph = new ArrayList[n];
        for(int i = 0; i < n; ++i) graph[i] = new ArrayList<>();
        for(List<Integer> edge : connections) {
            int u = edge.get(0), v = edge.get(1);
            graph[u].add(v);
            graph[v].add(u);
        }
        dfs(0, -1, graph);
        List<List<Integer>> ans = new ArrayList<>();
        for(List<Integer> edge : connections) {
            int u = edge.get(0), v = edge.get(1);
            if (lows[u] > times[v] || lows[v] > times[u]) ans.add(edge);
        }
        return ans;
    }
    
    public void dfs(int node, int parent, ArrayList<Integer>[] graph) {
        if (times[node] == INF) {
            lows[node] = time;
            times[node] = time;
            ++time;
            for(int nei : graph[node]) {
                if (times[nei] == INF) dfs(nei, node, graph);
            }
            for(int nei : graph[node]) {
                if (nei != parent) lows[node] = Math.min(lows[nei], lows[node]);
            }
        }
    }
    
    private int [] lows;
    private int [] times;
    private int time;
    private final int INF = 1000000;
}
