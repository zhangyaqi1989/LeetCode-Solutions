class Solution {
public:
    int numDistinct(string s, string t) {
        int ns = s.length(), nt = t.length();
        vector<vector<long long>> dp(nt + 1, vector<long long>(ns + 1, 0));
        for(int j = 0; j < ns + 1; ++j) dp[0][j] = 1;
        for(int i = 1; i < nt + 1; ++i) {
            for(int j = 1; j < ns + 1; ++j) {
                if (s[j - 1] == t[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[nt][ns];
    }
};
