class Solution {
    public int[] sortArrayByParity(int[] A) {
        int n = A.length;
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            while (lo < hi && A[lo] % 2 == 0) ++lo;
            while (lo < hi && A[hi] % 2 == 1) --hi;
            if (lo < hi) {
                int temp = A[lo];
                A[lo] = A[hi];
                A[hi] = temp;
            }
            ++lo;
            --hi;
        }
        return A;
    }
}
