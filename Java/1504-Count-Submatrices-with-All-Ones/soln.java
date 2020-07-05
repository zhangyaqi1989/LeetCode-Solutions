class Solution {
    public int numSubmat(int[][] mat) {
        int h = mat.length, w = mat[0].length;
        int [][] left_ones = new int [h][w];
        for(int i = 0; i < h; ++i) Arrays.fill(left_ones[i], 0);
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(mat[i][j] == 1) {
                    left_ones[i][j] = (j == 0) ? 1 : (left_ones[i][j - 1] + 1);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                int mn_left_ones = left_ones[i][j];
                int r = i;
                while(r >= 0 && mat[i][j] == 1) {
                    mn_left_ones = Math.min(mn_left_ones, left_ones[r][j]);
                    --r;
                    ans += mn_left_ones;
                }
            }
        }
        return ans;
    }
}
