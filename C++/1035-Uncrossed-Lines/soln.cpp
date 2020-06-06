class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int na = A.size(), nb = B.size();
        int dp[na + 1][nb + 1];
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= na; ++i) {
            for(int j = 1; j <= nb; ++j) {
                if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[na][nb];
    }
};
