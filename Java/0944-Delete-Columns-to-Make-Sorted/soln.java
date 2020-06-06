class Solution {
    public int minDeletionSize(String[] A) {
        int n = A.length, cnt = 0, m = A[0].length();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n - 1; ++j) {
                if (A[j].charAt(i) > A[j + 1].charAt(i)) {
                    ++cnt;
                    break;
                }
            }
        }
        return cnt;
    }
}
