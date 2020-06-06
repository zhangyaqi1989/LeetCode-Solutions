class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        int[][] prefixes = new int [32][n + 1];
        for(int i = 0; i < 32; ++i) {
            Arrays.fill(prefixes[i], 0);
        }
        for(int j = 0; j < n; ++j) {
            for(int i = 0; i < 32; ++i) {
                if ((arr[j] & (1 << i)) != 0) {
                    prefixes[i][j + 1] = prefixes[i][j] + 1;
                } else {
                    prefixes[i][j + 1] = prefixes[i][j];
                }
            }
        }
        int nqs = queries.length;
        int[] ans = new int[nqs];
        for(int j = 0; j < nqs; ++j) {
            int lo = queries[j][0], hi = queries[j][1];
            int val = 0;
            for(int i = 0; i < 32; ++i) {
                int cnt = prefixes[i][hi + 1] - prefixes[i][lo];
                if (cnt % 2 == 1) {
                    val |= (1 << i);
                }
            }
            ans[j] = val;
        }
        return ans;
    }
}
