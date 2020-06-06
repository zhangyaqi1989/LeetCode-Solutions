class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        List<Integer> [] children = new ArrayList[n];
        for(int i = 0; i < n; ++i) children[i] = new ArrayList<>();
        for(int i = 0; i < n; ++i) {
            if (manager[i] != -1) children[manager[i]].add(i);
        }
        int [] costs = new int[n];
        Arrays.fill(costs, -1);
        List<Integer> frontier = new ArrayList<>();
        frontier.add(headID);
        costs[headID] = 0;
        while(!frontier.isEmpty()) {
            List<Integer> next_level = new ArrayList<>();
            for(int u : frontier) {
                int c = costs[u];
                for(int v : children[u]) {
                    int new_cost = c + informTime[u];
                    if(costs[v] == -1 || costs[v] > new_cost) {
                        costs[v] = new_cost;
                        next_level.add(v);
                    }
                }
            }
            frontier = next_level;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) ans = Math.max(ans, costs[i]);
        return ans;
    }
}
