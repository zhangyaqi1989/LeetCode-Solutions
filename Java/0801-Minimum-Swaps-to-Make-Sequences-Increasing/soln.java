class Solution {
    public int minSwap(int[] A, int[] B) {
        int swap = 1, noswap = 0, n = A.length;
        for(int i = 1; i < n; ++i) {
            int temp_swap = Integer.MAX_VALUE, temp_noswap = Integer.MAX_VALUE;
            if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                temp_swap = Math.min(temp_swap, swap + 1);
                temp_noswap = Math.min(temp_noswap, noswap);
            }
            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                temp_swap = Math.min(temp_swap, noswap + 1);
                temp_noswap = Math.min(temp_noswap, swap);
            }
            swap = temp_swap;
            noswap = temp_noswap;
        }
        return Math.min(swap, noswap);
    }
}
