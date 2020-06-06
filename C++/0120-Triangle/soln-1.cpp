class Solution {
public:
    int minimumTotal(vector<vector<int>>& A) {
        // DP(i, j) = A[i, j] + min(DP[i + 1, j], DP[i + 1, j + 1])
        const int kN = A.size();
        vector<int> dp(A.back());
        for(int i = kN - 2; i >= 0; --i) {
            // in the i-th row, it has (i + 1) elements
            for(int j = 0; j <= i; ++j) {
                dp[j] = A[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};
