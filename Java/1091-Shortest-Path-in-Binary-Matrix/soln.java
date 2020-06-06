class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        if (grid[0][0] == 1) return -1;
        int n = grid.length;
        int [] dxs = {0,0,1,1,1,-1,-1,-1};
        int [] dys = {1,-1,0,1,-1,0,1,-1};
        Queue<int[]> frontier = new LinkedList<>();
        int [][] costs = new int [102][102];
        for(int [] row : costs) Arrays.fill(row, -1);
        costs[0][0] = 1;
        frontier.offer(new int [] {0, 0});
        while (!frontier.isEmpty()) {
            int [] node = frontier.poll();
            int x = node[0], y = node[1];
            if (x == n - 1 && y == n - 1) return costs[n - 1][n - 1];
            for(int i = 0; i < 8; ++i) {
                int nx = x + dxs[i], ny = y + dys[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < n && grid[nx][ny] == 0 && (costs[nx][ny] == -1 || costs[x][y] + 1 < costs[nx][ny])) {
                    costs[nx][ny] = costs[x][y] + 1;
                    frontier.offer(new int [] {nx, ny});
                }
            }
        }
        return -1;
    }
}
