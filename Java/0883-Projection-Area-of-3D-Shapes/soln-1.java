class Solution {
    public int projectionArea(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int [] rows = new int [m];
        int [] cols = new int [n];
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int val = grid[i][j];
                if (val > 0) ++ans;
                rows[i] = Math.max(rows[i], val);
                cols[j] = Math.max(cols[j], val);
            }
        }
        for(int i = 0; i < m; ++i) ans += rows[i];
        for(int j = 0; j < n; ++j) ans += cols[j];
        return ans;
    }
}
