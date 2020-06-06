class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        int target = (1 << n) - 1;
        Queue<int []> frontier = new LinkedList<>();
        for(int i = 0; i < n; ++i) frontier.offer(new int [] {i, 1 << i});
        boolean [][] seen = new boolean [12][1 << n];
        int step = 0;
        while (!frontier.isEmpty()) {
            int sz = frontier.size();
            for(int i = 0; i < sz; ++i) {
                int [] temp = frontier.poll();
                int node = temp[0], state = temp[1];
                if (state == target) return step;
                for(int nei : graph[node]) {
                    int new_state = (state | (1 << nei));
                    if (!seen[nei][new_state]) {
                        seen[nei][new_state] = true;
                        frontier.offer(new int [] {nei, new_state});
                    }
                }
            }
            ++step;
        }
        return step;
    }
}
