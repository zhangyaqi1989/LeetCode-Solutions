class Solution {
public:
    bool isMatch(string T, string P) {
        const int nt = T.length(), np = P.length();
        vector<vector<bool>> dp(nt + 1, vector<bool>(np + 1, false));
        dp[0][0] = true;
        for(int j = 2; j <= np + 1; j += 2) {
            if (P[j - 1] == '*') dp[0][j] = true;
            else break;
        }
        for(int i = 1; i < nt + 1; ++i) {
            for(int j = 1; j < np + 1; ++j) {
                if (T[i - 1] == P[j - 1] || P[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    if (P[j - 1] == '*') {
                        dp[i][j] = (dp[i][j - 2]) || (dp[i - 1][j - 2] && (T[i - 1] == P[j - 2] || P[j - 2] == '.')) || (dp[i - 1][j] && (T[i - 1] == P[j - 2] || P[j - 2] == '.'));
                    }
                }
            }
        }
        return dp[nt][np];
    }
};
