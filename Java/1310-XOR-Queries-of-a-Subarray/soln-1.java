class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        for(int i = 1; i < n; ++i) arr[i] ^= arr[i - 1];
        int [] ans = new int[queries.length];
        for(int i = 0; i < queries.length; ++i) {
            int [] q = queries[i];
            int lo = q[0], hi = q[1];
            ans[i] = (lo == 0 ? arr[hi] : (arr[hi] ^ arr[lo - 1]));
        }
        return ans;
    }
}
