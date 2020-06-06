class Solution {
    public int[] prevPermOpt1(int[] A) {
        int n = A.length;
        for(int i = n - 1; i > 0; --i) {
            if (A[i] < A[i - 1]) {
                for(int j = n - 1; j > 0; --j) {
                    if (A[j] < A[i - 1]) {
                        int temp = A[i - 1];
                        A[i - 1] = A[j];
                        A[j] = temp;
                        return A;
                    }
                }
            }
        }
        return A;
    }
}
