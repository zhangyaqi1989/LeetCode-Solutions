class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        // A[i:j] is turbulent
        // i <= k < j, A[k] > A[k + 1] when k is odd and A[k] < A[k + 1] when k is even
        // [4,8,12,16]
        // O(n^3)
        // n = 1, max_len = 1
        // DP problem
        // subproblem DP(n) is maximum subarray in A[:n], also ends at A[n - 1]
        // in order to compute A[:n], max_inc, max_dec, 
        // max subarray of A[:n - 1] that increase in the last step: max_inc
        // [4, 8, 12, 16]
        // max_inc = 1, max_dec = 1
        // i = 1, max_inc = 2, max_dec = 1
        // i = 2, max_inc = 2, max_dec = 1
        // i = 3, max_inc = 2, max_dec = 1
        const int kN = A.size();
        int max_inc = 1, max_dec = 1;
        int ans = 1;
        for(int i = 1; i < kN; ++i) {
            if (A[i] > A[i - 1]) {
                max_inc = max_dec + 1;
                max_dec = 1;
                ans = max(max_inc, ans);
            } else if (A[i] < A[i - 1]) {
                max_dec = max_inc + 1;
                max_inc = 1;
                ans = max(max_dec, ans);
            } else {
                max_inc = 1;
                max_dec = 1;
            }
        }
        return ans;
    }
};
