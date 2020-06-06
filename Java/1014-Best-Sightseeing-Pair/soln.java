class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        int ans = -100000;
        int max_seen = -100000;
        int n = A.length;
        for(int i = 0; i < n; ++i) {
            if (max_seen + A[i] - i > ans) ans = max_seen + A[i] - i;
            if (A[i] + i > max_seen) max_seen = A[i] + i;
            // max_seen = Math.max(max_seen, A[i] + i);
        }
        return ans;
    }
}
