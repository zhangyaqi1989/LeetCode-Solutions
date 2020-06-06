class Solution {
    private static int[] dis = {0, 0, 1, -1};
    private static int[] djs = {1, -1, 0, 0};
    public int numDistinctIslands(int[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) return 0;
        Set<List<List<Integer>>> islands = new HashSet<>();
        int m = grid.length, n = grid[0].length;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    List<List<Integer>> island = new ArrayList<>();
                    dfs(i, j, i, j, grid, island);
                    islands.add(island);
                }
            }
        }
        return islands.size();
    }
    
    private void dfs(int i0, int j0, int i, int j, int[][] grid, List<List<Integer>> island) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == 0) return;
        grid[i][j] = 0;
        island.add(Arrays.asList(i - i0, j - j0));
        for(int k = 0; k < 4; ++k) {
            int di = dis[k];
            int dj = djs[k];
            dfs(i0, j0, i + di, j + dj, grid, island);
        }
    }
    
    
    
}
