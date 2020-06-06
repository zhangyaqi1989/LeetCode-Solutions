class Solution {
    public int minKBitFlips(int[] A, int K) {
        int cur = 0, cnt = 0, n = A.length;
        for(int i = 0; i < n; ++i) {
            if (i >= K) cur -= A[i - K] / 2;
            if (((cur % 2) ^ A[i]) == 0) {
                if (i + K > n) return -1;
                A[i] += 2;
                ++cnt;
                ++cur;
            }
        }
        return cnt;
    }
}
