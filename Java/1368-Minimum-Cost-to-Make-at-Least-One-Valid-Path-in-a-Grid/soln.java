class Solution {
    public int minCost(int[][] grid) {
        int [][] dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = grid.length, n = grid[0].length;
        int [][] costs = new int [m][n];
        final int INF = 1000000;
        for(int i = 0; i < m; ++i) Arrays.fill(costs[i], INF);
        costs[0][0] = 0;
        Queue<int []> frontier = new LinkedList<>();
        frontier.offer(new int [] {0, 0});
        while(!frontier.isEmpty()) {
            int [] node = frontier.poll();
            int r = node[0], c = node[1];
            for(int k = 1; k < 5; ++k) {
                int dr = dirs[k][0], dc = dirs[k][1];
                int nr = r + dr;
                int nc = c + dc;
                if (0 <= nr && nr < m && 0 <= nc && nc < n) {
                    int weight = (k == grid[r][c]) ? 0 : 1;
                    int new_weight = weight + costs[r][c];
                    if (costs[nr][nc] > new_weight) {
                        costs[nr][nc] = new_weight;
                        frontier.offer(new int[] {nr, nc});
                    }
                }
            }
        }
        return costs[m - 1][n - 1];
    }
}
