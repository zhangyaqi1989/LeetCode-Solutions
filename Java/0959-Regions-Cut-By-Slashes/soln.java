class Solution {
    public int regionsBySlashes(String[] grid) {
        int n = grid.length;
        int m = 3 * n;
        int[][] matrix = new int[m][m];
        for(int [] row : matrix) {
            Arrays.fill(row, 0);
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if (grid[i].charAt(j) == '/') {
                    int I = 3 * i, J = 3 * j;
                    matrix[I][J + 2] = 1;
                    matrix[I + 1][J + 1] = 1;
                    matrix[I + 2][J] = 1;
                } else if (grid[i].charAt(j) == '\\') {
                    int I = 3 * i, J = 3 * j;
                    matrix[I][J] = 1;
                    matrix[I + 1][J + 1] = 1;
                    matrix[I + 2][J + 2] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    dfs(i, j, matrix);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
    
    public void dfs(int i, int j, int[][] matrix) {
        if (i < 0 || i >= matrix.length || j < 0 || j >= matrix[0].length || matrix[i][j] != 0) return;
        matrix[i][j] = 1;
        dfs(i - 1, j, matrix);
        dfs(i + 1, j, matrix);
        dfs(i, j - 1, matrix);
        dfs(i, j + 1, matrix);
    }
}
