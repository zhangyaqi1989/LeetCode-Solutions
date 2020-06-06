class Solution {
    public int numEnclaves(int[][] A) {
        int m = A.length, n = A[0].length;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    dfs(i, j, A);
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (A[i][j] == 1) ++cnt;
            }
        }
        return cnt;
        
    }
    
    public void dfs(int i, int j, int[][] A) {
        if (i >= 0 && i < A.length && j >= 0 && j < A[0].length && A[i][j] == 1) {
            A[i][j] = 0;
            dfs(i - 1, j, A);
            dfs(i + 1, j, A);
            dfs(i, j - 1, A);
            dfs(i, j + 1, A);
        }
    }
}
