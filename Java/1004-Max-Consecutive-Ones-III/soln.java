class Solution {
    public int longestOnes(int[] A, int K) {
        int ans = 0, zeros = 0;
        int l = 0, n = A.length;
        for(int r = 0; r < n; ++r) {
            if (A[r] == 0) ++zeros;
            while (zeros > K) {
                if(A[l++] == 0) --zeros;
            }
            ans = Math.max(ans, r - l + 1);
        }
        return ans;
    }
}
