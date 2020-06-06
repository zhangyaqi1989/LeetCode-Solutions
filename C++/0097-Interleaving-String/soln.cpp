class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3) return false;
        bool dp[n1 + 1][n2 + 1];
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n1 + 1; ++i) {
            for(int j = 0; j < n2 + 1; ++j) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else if (i == 0) {
                    if (s2[j - 1] == s3[j - 1] && dp[i][j - 1]) dp[i][j] = true;
                } else if (j == 0) {
                    if (s1[i - 1] == s3[i - 1] && dp[i - 1][j]) dp[i][j] = true;
                } else {
                    if ((s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]))
                        dp[i][j] = true;
                }
            }
        }
        return dp[n1][n2];
        
    }
};
