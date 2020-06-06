class Solution {
    public boolean validMountainArray(int[] A) {
        int n = A.length;
        boolean inc = true;
        for(int i = 1; i < n; ++i) {
            if (A[i] > A[i - 1]) {
                if (!inc) return false;
            } else if (A[i] < A[i - 1]) {
                inc = false;
            } else return false;
        }
        return !inc && A[1] > A[0];
    }
}
