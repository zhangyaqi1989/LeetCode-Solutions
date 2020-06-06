class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        // want to reduce the difference in A
        // add 0 or 2 * K, add 2 * K to the first portion, add 0 to the second portion
        // search the partition point
        sort(A.begin(), A.end());
        K = K * 2;
        int res = A[A.size() - 1] - A[0];
        for(int i = 0; i < A.size() - 1; ++i) {
            int mn = min(A[i + 1], A[0] + K);
            int mx = max(A[i] + K, A[A.size() - 1]);
            res = min(mx - mn, res);
        }
        return res;
    }
};