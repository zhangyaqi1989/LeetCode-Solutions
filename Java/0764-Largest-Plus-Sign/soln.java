class Solution {
    public int orderOfLargestPlusSign(int N, int[][] mines) {
        int[][] grid = new int[N][N];
        // assume no mine in grid
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                grid[i][j] = Math.min(Math.min(i, j), Math.min(N - 1 - i, N - 1 - j)) + 1;
            }
        }
        for(int [] mine : mines) {
            int r = mine[0], c = mine[1];
            for(int idx = 0; idx < N; ++idx) {
                grid[r][idx] = Math.min(grid[r][idx], Math.abs(idx - c));
                grid[idx][c] = Math.min(grid[idx][c], Math.abs(idx - r));
            }
        }
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                ans = Math.max(ans, grid[i][j]);
            }
        }
        return ans;
    }
}
