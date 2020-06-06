class Solution {
    public int matrixScore(int[][] A) {
        int m = A.length, n = A[0].length;
        boolean[] row_flip = new boolean[m];
        for(int i = 0; i < m; ++i) {
            if (A[i][0] == 0) row_flip[i] = true;
            else row_flip[i] = false;
        }
        int ans = 0;
        for(int j = 0; j < n; ++j) {
            int ones = 0;
            for(int i = 0; i < m; ++i) {
                if ((row_flip[i] && A[i][j] == 0) || (!row_flip[i] && A[i][j] == 1)) ++ones;
            }
            ans = ans * 2 + Math.max(ones, m - ones);
        }
        return ans;
    }
}
