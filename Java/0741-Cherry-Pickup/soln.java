class Solution {
    public Map<String, Integer> memo;
    public int cherryPickup(int[][] grid) {
        memo = new HashMap<>();
        int ans = helper(grid, 0, 0, 0, 0);
        return ans == -1 ? 0 : ans;
    }
    
    public int helper(int[][] grid, int i1, int j1, int i2, int j2) {
        String key = i1 + " " + j1 + " " + i2 + " " + j2;
        if (memo.containsKey(key)) return memo.get(key);
        int N = grid.length;
        if (i1 == N || j1 == N || i2 == N || j2 == N) return -1;
        if (grid[i1][j1] == -1 || grid[i2][j2] == -1) return -1;
        if (i1 == N - 1 && j1 == N - 1 && i2 == N - 1 && j2 == N - 1) return grid[N-1][N-1];
        int n1 = helper(grid, i1 + 1, j1, i2 + 1, j2);
        int n2 = helper(grid, i1 + 1, j1, i2, j2 + 1);
        int n3 = helper(grid, i1, j1 + 1, i2 + 1, j2);
        int n4 = helper(grid, i1, j1 + 1, i2, j2 + 1);
        int ans = Math.max(Math.max(n1, n2), Math.max(n3, n4));
        if (ans != -1) {
            if (i1 == i2 && j1 == j2) ans += grid[i1][j1];
            else ans += grid[i1][j1] + grid[i2][j2];
        }
        memo.put(key, ans);
        return ans;
    }
}
