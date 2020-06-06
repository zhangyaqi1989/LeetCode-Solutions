class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        // DP[i] is s[i:] can be formed
        const int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for(int i = n - 1; i >= 0; --i) {
            for(int j = i + 1; j <= n; ++j) {
                if (words.count(s.substr(i, j - i)) && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
