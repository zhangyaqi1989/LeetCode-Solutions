class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        int [] rows = new int [n];
        int [] cols = new int [m];
        for(int [] indice : indices) {
            ++rows[indice[0]];
            ++cols[indice[1]];
        }
        int ans = 0;
        for(int r = 0; r < n; ++r) {
            for(int c = 0; c < m; ++c) {
                ans += (rows[r] + cols[c]) % 2;
            }
        }
        return ans;
    }
}
