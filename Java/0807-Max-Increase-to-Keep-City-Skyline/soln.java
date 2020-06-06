class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int [] rows = new int[m];
        int [] cols = new int[n];
        for(int i = 0; i < m; ++i) {
            int mx = Integer.MIN_VALUE;
            for(int j = 0; j < n; ++j) mx = Math.max(mx, grid[i][j]);
            rows[i] = mx;
        }
        for(int j = 0; j < n; ++j) {
            int mx = Integer.MIN_VALUE;
            for(int i = 0; i < m; ++i) mx = Math.max(mx, grid[i][j]);
            cols[j] = mx;
        }
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                ans += Math.min(rows[i], cols[j]) - grid[i][j];
            }
        }
        return ans;
    }
}
