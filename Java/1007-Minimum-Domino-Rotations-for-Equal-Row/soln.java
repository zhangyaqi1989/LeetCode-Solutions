class Solution {
    public int minDominoRotations(int[] A, int[] B) {
        int n = A.length;
        int ans = n + 1;
        for(int val = 1; val <= 6; ++val) {
            boolean valid = true;
            int na = 0, nb = 0;
            for(int i = 0; i < n; ++i) {
                if (val != A[i] && val != B[i]) {
                    valid = false;
                    break;
                }
                if (val != A[i]) ++na;
                if (val != B[i]) ++nb;
            }
            if (valid) ans = Math.min(ans, Math.min(na, nb));
        }
        return ans == n + 1 ? -1 : ans;
    }
}
