class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int flips = 0;
        int curFlips = 0;
        for(int i = 0; i < n; ++i) {
            if (i >= K) curFlips -= A[i - K] / 2;
            if (((curFlips & 1) ^ A[i]) == 0) {
                if (i + K > n) return -1;
                ++flips;
                ++curFlips;
                A[i] += 2;
            }
        }
        return flips;
    }
};
