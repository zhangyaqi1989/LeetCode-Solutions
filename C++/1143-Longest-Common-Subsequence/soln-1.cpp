class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i < m + 1; ++i) {
            for(int j = 1; j < n + 1; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        // return dp[m][n];
        int i = m, j = n;
        string ans = "";
        while (dp[i][j] > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                ans += text1[i - 1];
                --i;
                --j;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    --i;
                } else {
                    --j;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans.length();
    }
};
