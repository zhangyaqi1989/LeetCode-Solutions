class Solution {
public:
    string shortestCommonSupersequence(string A, string B) {
        int m = A.length(), n = B.length();
        vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + A[i - 1];
                else dp[i][j] = dp[i - 1][j].length() > dp[i][j - 1].length() ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
        string lcs = dp[m][n];
        int i = 0, j = 0;
        string ans = "";
        for(char ch : lcs) {
            while (i < m && A[i] != ch) ans += A[i++];
            while (j < n && B[j] != ch) ans += B[j++];
            ++i;
            ++j;
            ans += ch;
        }
        return ans + A.substr(i) + B.substr(j);
    }
};
