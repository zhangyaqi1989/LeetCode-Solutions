class Solution {
    public boolean isIdealPermutation(int[] A) {
        // [1, 0, 2]
        // [0, 1, 2]
        // no non-local inversion
        int n = A.length;
        int mx_seen = -1;
        for(int i = 0; i < n; ++i) {
            if (mx_seen > A[i]) return false;
            if(i - 1 >= 0) mx_seen = Math.max(mx_seen, A[i - 1]);
        }
        return true;
    }
}
