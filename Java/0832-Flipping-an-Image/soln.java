class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int m = A.length, n = A[0].length;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n / 2; ++j) {
                int temp = A[i][j];
                A[i][j] = A[i][n - 1 - j];
                A[i][n - 1 - j] = temp;
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                A[i][j] = 1 - A[i][j];
            }
        }
        return A;        
    }
}
