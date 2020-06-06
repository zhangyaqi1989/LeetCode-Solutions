class Solution {
    public int longestMountain(int[] A) {
        int n = A.length;
        int up = 0, down = 0, ans = 0;
        for(int i = 1; i < n; ++i) {
            if ((down > 0 && A[i] >= A[i - 1]) || (A[i] == A[i - 1])) up = down = 0;
            up += A[i] > A[i - 1] ? 1 : 0;
            down += A[i] < A[i - 1] ? 1 : 0;
            if (up > 0 && down > 0) ans = Math.max(ans, up + down + 1); 
        }
        return ans;
    }
}
