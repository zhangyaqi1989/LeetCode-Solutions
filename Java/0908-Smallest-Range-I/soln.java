class Solution {
    public int smallestRangeI(int[] A, int K) {
        int mn = A[0], mx = A[0];
        for(int num : A) {
            mn = Math.min(mn, num);
            mx = Math.max(mx, num);
        }
        if (mx - mn > 2 * K) return mx - mn - 2 * K;
        else return 0;
    }
}
