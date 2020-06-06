class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        if (n <= 2) return n;
        vector<unordered_map<int, int>> dp(n);
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i - 1; j >= 0; --j) {
                dp[i][A[i] - A[j]] = max(dp[i][A[i] - A[j]], dp[j][A[i] - A[j]] + 1);
                cnt = max(cnt, dp[i][A[i] - A[j]]);
            }
        }
        return cnt + 1;
    }
};
