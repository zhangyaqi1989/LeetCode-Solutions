class Solution {
    public int longestArithSeqLength(int[] A) {
        int n = A.length;
        Map<Integer, Integer> [] dp = new HashMap[n];
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            dp[i] = new HashMap<>();
            for(int j = i - 1; j >= 0; --j) {
                dp[i].put(A[i] - A[j], Math.max(dp[i].getOrDefault(A[i] - A[j], 0), dp[j].getOrDefault(A[i] - A[j], 0) + 1));
                cnt = Math.max(cnt, dp[i].get(A[i] - A[j]));
            }
        }
        return cnt + 1;
    }
}
