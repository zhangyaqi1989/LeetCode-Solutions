class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            int val = A[i] + dp[i];
            int mx = A[i];
            int cnt = 1;
            for(int j = i - 1; j >= max(0, i - K + 1); --j) {
                ++cnt;
                mx = max(mx, A[j]);
                val = max(val, dp[j] + mx * cnt);
            }
            dp[i + 1] = val;
        }
        return dp[n];
    }
};
