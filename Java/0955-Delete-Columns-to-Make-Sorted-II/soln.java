class Solution {
    public int minDeletionSize(String[] A) {
        int n = A.length;
        boolean[] done = new boolean[n - 1];
        int ndone = 0;
        int cnt = 0;
        int m = A[0].length();
        for(int i = 0; i < m; ++i) {
            boolean del_col = false;
            for(int j = 0; j < n - 1; ++j) {
                if (A[j].charAt(i) > A[j + 1].charAt(i) && !done[j]) {
                    del_col = true;
                    break;
                }
            }
            if (del_col) {
                ++cnt;
            } else {
                for(int j = 0; j < n - 1; ++j) {
                    if (A[j].charAt(i) < A[j + 1].charAt(i) && !done[j]) {
                        done[j] = true;
                        ++ndone;
                    }
                }
            }
            if (ndone == n - 1) break;
        }
        return cnt;
    }
}
