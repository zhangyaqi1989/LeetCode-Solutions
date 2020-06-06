class Solution {
public:
    string minWindow(string S, string T) {
        int ns = S.length(), nt = T.length();
        vector<vector<int>> dp(nt + 1, vector<int>(ns + 1, -1));
        for(int j = 0; j < ns + 1; ++j) {
            dp[0][j] = j;
        }
        for(int i = 1; i < nt + 1; ++i) {
            for(int j = 1; j < ns + 1; ++j) {
                if (T[i - 1] == S[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = dp[i][j - 1];
            }
        }
        int start = 0, len = ns + 1;
        for(int j = 0; j < ns + 1; ++j) {
            if (dp[nt][j] != -1) {
                if (j - dp[nt][j] < len || (j - dp[nt][j] == len && dp[nt][j] < start)) {
                    start = dp[nt][j];
                    len = j - dp[nt][j];
                }
            }
        }
        return len == ns + 1 ? "" : S.substr(start, len);
    }
};
