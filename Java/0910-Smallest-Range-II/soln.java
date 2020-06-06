class Solution {
    public int smallestRangeII(int[] A, int K) {
        int n = A.length;
        Arrays.sort(A);
        int mn = A[n - 1] - A[0];
        K *= 2;
        for(int i = 0; i < n - 1; ++i) {
            int cur_mn = Math.min(A[i + 1], A[0] + K);
            int cur_mx = Math.max(A[i] + K, A[n - 1]);
            mn = Math.min(mn, cur_mx - cur_mn);
        }
        return mn;
    }
}
