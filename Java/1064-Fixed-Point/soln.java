class Solution {
    public int fixedPoint(int[] A) {
        int n = A.length;
        for(int i = 0; i < n; ++i) {
            if (i == A[i]) return i;
        }
        return -1;
    }
}
