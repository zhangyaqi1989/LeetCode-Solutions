class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        for(int i = 0; i < n1 + 1; ++i) {
            for (int j = 0; j < n2 + 1; ++j) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else {
                    if ((i > 0 && s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || (j > 0 && s2[j - 1] == s3[i + j - 1] && dp[i][j - 1])) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        return dp[n1][n2];
    }
};
