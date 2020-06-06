class Solution {
    public boolean isIdealPermutation(int[] A) {
        // 0 <= i < j < N and A[i] > A[j]
        // 0 <= i < N and A[i] > A[i + 1]
        int n_globals = 0, n_locals = 0;
        int n = A.length;
        for(int i = 0; i < n; ++i) {
            if(i + 1 < n && A[i] > A[i + 1]) ++n_locals;
            for(int j = i + 1; j < n; ++j) {
                if(A[i] > A[j]) ++n_globals;
            }
        }
        return n_globals == n_locals;
    }
}
