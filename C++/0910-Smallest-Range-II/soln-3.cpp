class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        const int kN = A.size();
        int min_range = A[kN - 1] - A[0];
        for(int i = 0; i < kN - 1; ++i) {
            int cur_min = min(A[0] + K, A[i + 1] - K);
            int cur_max = max(A[i] + K, A.back() - K);
            min_range = min(min_range, cur_max - cur_min);
        }
        return min_range;
    }
};
