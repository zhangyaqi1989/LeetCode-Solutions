class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int mx = 0;
        for(int i = 0; i < grid.length; ++i) {
            for(int j = 0; j < grid[0].length; ++j) {
                if (grid[i][j] == 1) mx = Math.max(mx, dfs(i, j, grid));
            }
        }
        return mx;
    }
    
    public int dfs(int i, int j, int[][] grid) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        return 1 + dfs(i - 1, j, grid) + dfs(i + 1, j, grid) + dfs(i, j - 1, grid) + dfs(i, j + 1, grid);
    }
}
