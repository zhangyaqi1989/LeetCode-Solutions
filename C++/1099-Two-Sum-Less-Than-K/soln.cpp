class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        const int kN = A.size();
        int best = -1;
        for(int i = 0; i < kN; ++i) {
            for(int j = i + 1; j < kN; ++j) {
                if(A[i] + A[j] < K) {
                    best = max(best, A[i] + A[j]);
                }
            }
        }
        return best;
    }
};
