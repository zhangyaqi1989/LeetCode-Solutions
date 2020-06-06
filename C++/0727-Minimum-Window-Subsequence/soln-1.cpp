class Solution {
public:
    string minWindow(string S, string T) {
        const int ns = S.length(), nt = T.length();
        const int INF = 200000;
        vector<vector<int>> dp(ns + 1, vector<int>(nt + 1, INF));
        for(int i = 0; i <= ns; ++i) dp[i][nt] = 0;
        for(int i = ns - 1; i >= 0; --i) {
            for(int j = nt - 1; j >= 0; --j) {
                if (S[i] == T[j]) dp[i][j] = min(dp[i][j], dp[i + 1][j + 1] + 1);
                else {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                }
            }
        }
        string ans = "";
        int mn = INF;
        for(int i = 0; i < ns + 1; ++i) {
            if (dp[i][0] < mn) {
                ans = S.substr(i, dp[i][0]);
                mn = dp[i][0];
            }
        }
        return ans;
    }
};
