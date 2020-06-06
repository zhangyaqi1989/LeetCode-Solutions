class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int m = nums.length, n = nums[0].length;
        if (r * c != m * n) return nums;
        int [][] ans = new int[r][c];
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int idx = i * n + j;
                int nr = idx / c;
                int nc = idx % c;
                ans[nr][nc] = nums[i][j];
            }
        }
        return ans;
    }
}
