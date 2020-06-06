class Solution {
    public int[][] imageSmoother(int[][] M) {
        int m = M.length, n = M[0].length;
        int [][] ans = new int [m][n];
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int sum = 0;
                int cnt = 0;
                for(int di = -1; di <= 1; ++di) {
                    for(int dj = -1; dj <= 1; ++dj) {
                        int ni = i + di, nj = j + dj;
                        if (0 <= ni && ni < m && 0 <= nj && nj < n) {
                            sum += M[ni][nj];
                            ++cnt;
                        }
                    }
                }
                ans[i][j] = sum / cnt;
            }
        }
        return ans;
    }
}
