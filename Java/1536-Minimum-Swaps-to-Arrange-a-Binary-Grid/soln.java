class Solution {
    public int minSwaps(int[][] grid) {
        final int N = grid.length;
        int [] trailing_zeros = new int [N];
        for(int i = 0; i < N; ++i) {
            int j = N - 1;
            while(j >= 0 && grid[i][j] == 0) --j;
            trailing_zeros[i] = N - 1 - j;
        }
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            int req = N - 1 - i;
            int idx = i;
            while(idx < N && trailing_zeros[idx] < req) ++idx;
            if(idx == N) return -1;
            ans += idx - i;
            while(idx > i) {
                trailing_zeros[idx] = trailing_zeros[idx - 1];
                --idx;
            }
        }
        return ans;
    }
}
