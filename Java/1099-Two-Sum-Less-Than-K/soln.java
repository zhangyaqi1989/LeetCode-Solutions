class Solution {
    public int twoSumLessThanK(int[] A, int K) {
        int n = A.length;
        int best = -1;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(A[i] + A[j] < K) {
                    best = Math.max(best, A[i] + A[j]);
                }
            }
        }
        return best;
    }
}
