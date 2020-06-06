class Solution {
public:
    int longestRepeatingSubstring(string S) {
        int n = S.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                if (S[i - 1] == S[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
