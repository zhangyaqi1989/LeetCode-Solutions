class Solution {
    public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
        int n = R * C;
        int[][] ans = new int[n][2];
        int [] drs = {0, 1, 0, -1};
        int [] dcs = {1, 0, -1, 0};
        int r = r0, c = c0;
        int face = 0;
        int step = 0;
        int cur = 0, cnt = 0;
        while (cnt < n) {
            if (cur % 2 == 0) {
                ++step;
            }
            cur += 1;
            int dr = drs[face], dc = dcs[face];
            face = (face + 1) % 4;
            for(int i = 0; i < step; ++i) {
                if(0 <= r && r < R && 0 <= c && c < C) {
                    ans[cnt][0] = r;
                    ans[cnt][1] = c;
                    ++cnt;
                }
                r += dr;
                c += dc;
            }
        }
        return ans;
    }
}
