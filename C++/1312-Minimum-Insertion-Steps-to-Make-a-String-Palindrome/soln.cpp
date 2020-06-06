class Solution {
public:
    int minInsertions(string s) {
        const int kN = s.length();
        vector<vector<int>> dp(kN, vector<int>(kN, 0));
        for(int len = 2; len <= kN; ++len) {
            for(int lo = 0; lo + len - 1 < kN; ++lo) {
                if (s[lo] == s[lo + len - 1]) {
                    dp[lo][lo + len - 1] = dp[lo + 1][lo + len - 2];
                } else {
                    dp[lo][lo + len - 1] = 1 + min(dp[lo + 1][lo + len - 1], dp[lo][lo + len - 2]);
                }
            }
        }
        return dp[0][kN - 1];
    }
};
