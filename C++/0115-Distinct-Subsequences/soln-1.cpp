typedef long long ll;
class Solution {
public:
    int numDistinct(string s, string t) {
        const int kSLen = s.length(), kTLen = t.length();
        vector<vector<ll>> dp(kSLen + 1, vector<ll>(kTLen + 1, 0));
        for(int i = 0; i < kSLen + 1; ++i) dp[i][kTLen] = 1;
        for(int i = kSLen - 1; i >= 0; --i) {
            for(int j = kTLen - 1; j >= 0; --j) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};
