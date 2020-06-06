class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        const int n = A.size();
        vector<unordered_map<int, int>> dp(n);
        int mx = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                int d = A[i] - A[j];
                dp[i][d] = max(dp[i][d], dp[j][d] + 1);
                mx = max(mx, dp[i][d]);
            }
        }
        return mx + 1;
        
    }
};
