class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.length(), np = p.length();
        vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1, false));
        dp[0][0] = true;
        for(int j = 2; j < np + 1; j += 2) {
            if (p[j - 1] == '*' && dp[0][j - 2]) dp[0][j] = true; 
        }
        for(int i = 1; i < ns + 1; ++i) {
            for(int j = 1; j < np + 1; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') dp[i][j] = dp[i - 1][j - 1];
                if (p[j - 1] == '*') {
                    if (p[j - 2] != s[i - 1] && p[j - 2] != '.') dp[i][j] = dp[i][j - 2];
                    else {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[ns][np];
    }
};
