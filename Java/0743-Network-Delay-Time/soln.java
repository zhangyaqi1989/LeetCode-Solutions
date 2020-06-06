class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        List<int []> [] graph = new ArrayList[N + 1];
        for(int i = 0; i < N + 1; ++i) graph[i] = new ArrayList<>();
        for(int [] e : times) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].add(new int [] {v, w});
        }
        Queue<int []> frontier = new LinkedList<>();
        int [] costs = new int [N + 1];
        Arrays.fill(costs, Integer.MAX_VALUE);
        costs[K] = 0;
        frontier.offer(new int [] {0, K});
        while(!frontier.isEmpty()) {
            int [] top = frontier.poll();
            int cost = top[0], u = top[1];
            for(int [] e : graph[u]) {
                int v = e[0], w = e[1];
                if (cost + w < costs[v]) {
                    costs[v] = cost + w;
                    frontier.offer(new int [] {cost + w, v});
                }
            }
        }
        int ans = -1;
        for(int i = 1; i <= N; ++i) {
            if (costs[i] == Integer.MAX_VALUE) return -1;
            ans = Math.max(costs[i], ans);
        }
        return ans;
    }
}
