class Solution {
    public int maxSumTwoNoOverlap(int[] A, int L, int M) {
        int acc = 0, n = A.length;
        int [] accs = new int [n + 1];
        for(int i = 0; i < n; ++i) {
            acc += A[i];
            accs[i + 1] = acc;
        }
        n = accs.length;
        int ans = Integer.MIN_VALUE;
        for(int i = L; i < n; ++i) {
            int lacc = accs[i] - accs[i - L];
            int macc = Integer.MIN_VALUE;
            for(int j = M; j <= i - L; ++j) {
                macc = Math.max(macc, accs[j] - accs[j - M]);
            }
            for(int j = i; j + M < n; ++j) {
                macc = Math.max(macc, accs[j + M] - accs[j]);
            }
            ans = Math.max(ans, lacc + macc);
        }
        return ans;
    }
    
}
