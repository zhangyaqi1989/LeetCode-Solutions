class Solution {
    public int minFallingPathSum(int[][] arr) {
        int m = arr.length, n = arr[0].length;
        final int INF = 500000;
        for(int i = 1; i < m; ++i) {
            int mn = INF;
            int mn_idx = -1;
            int second_mn = INF;
            for(int j = 0; j < n; ++j) {
                if (arr[i - 1][j] <= mn) {
                    second_mn = mn;
                    mn_idx = j;
                    mn = arr[i - 1][j];
                } else if (arr[i - 1][j] < second_mn) {
                    second_mn = arr[i - 1][j];
                }
            }
            for(int j = 0; j < n; ++j) {
                arr[i][j] += (j == mn_idx ? second_mn : mn);
            }
        }
        int ans = INF;
        for(int j = 0; j < n; ++j) {
            if (arr[m - 1][j] < ans) ans = arr[m - 1][j];
        }
        return ans;
    }
}
