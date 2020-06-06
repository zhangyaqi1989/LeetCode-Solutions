class Solution {
    public int projectionArea(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int front = 0, side = 0, top = 0;
        for(int i = 0; i < m; ++i) {
            int temp = 0;
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) ++top;
                if (grid[i][j] > temp) temp = grid[i][j];
            }
            side += temp;
        }
        for(int j = 0; j < n; ++j) {
            int temp = 0;
            for(int i = 0; i < m; ++i) {
                if (grid[i][j] > temp) temp = grid[i][j];
            }
            front += temp;
        }
        return front + side + top;
    }
}
