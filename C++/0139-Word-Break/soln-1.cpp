class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp = {true};
        for(int i = 1; i <= n; ++i) {
            bool isin = false;
            for(int j = i - 1; j >= 0; --j) {
                if (words.count(s.substr(j, i - j)) && dp[j]) {
                    isin = true;
                    break;
                }
            }
            dp.push_back(isin);
        }
        return dp[n];
    }
};
