class Solution {
    public int findTheCity(int n, int[][] edges, int threshold) {
        List<int []> [] graph = new ArrayList[n];
        for(int i = 0; i < n; ++i) {
            graph[i] = new ArrayList<>();
        }
        for(int [] edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].add(new int[] {v, w});
            graph[v].add(new int[] {u, w});
        }
            // System.out.println(cnt);
            if (cnt <= mn) {
                idx = i;
                mn = cnt;
            }
        }
        return idx;
    }
    
    private int dijkstra(List<int []> [] graph, int start, int n, int threshold) {
        PriorityQueue<int []> frontier = new PriorityQueue<>(100, (a, b) -> (a[0] - b[0]));
        Map<Integer, Integer> costs = new HashMap<>();
        costs.put(start, 0);
        frontier.offer(new int [] {0, start});
        boolean [] processed = new boolean[n];
        while (!frontier.isEmpty()) {
            int [] node = frontier.poll();
            int u = node[1], cost = node[0];
            if (processed[u]) continue;
            processed[u] = true;
            // System.out.println(u);
            for(int [] nei : graph[u]) {
                // System.out.println(nei[0]);
                // System.out.println(costs.containsKey(nei[0]));
                int v = nei[0], w = nei[1];
                if (cost + w <= threshold && (!costs.containsKey(v) || cost + w < costs.get(v))) {
                    // System.out.println(nei[0] + "H");
                    costs.put(v, cost + w);
                    frontier.offer(new int [] {cost + w, v});
                }
            }
        }
        return costs.size() - 1;
    }
}        int idx = 0, mn = n + 1;
        for(int i = 0; i < n; ++i) {
            int cnt = dijkstra(graph, i, n, threshold);

