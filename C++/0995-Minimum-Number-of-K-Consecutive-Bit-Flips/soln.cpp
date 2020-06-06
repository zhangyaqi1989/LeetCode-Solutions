class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int flips = 0;
        for(int i = 0; i < n - K + 1; ++i) {
            if (A[i] == 0) {
                flips += 1;
                for(int j = i; j < i + K; ++j)
                    A[j] ^= 1;
            }
        }
        for(int i = 0; i < n; ++i) {
            if (A[i] == 0) return -1;
        }
        return flips;
    }
};
