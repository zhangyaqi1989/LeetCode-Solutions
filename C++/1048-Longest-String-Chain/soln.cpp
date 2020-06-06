class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<unordered_set<string>> d(17);
        unordered_map<string, int> dp;
        for(string word : words) {
            dp[word] = 1;
            d[word.length()].insert(word);
        }
        for(int i = 2; i < 17; ++i) {
            for(string word : d[i]) {
                for(int j = 0; j < i; ++j) {
                    string new_word = word.substr(0, j) + word.substr(j + 1);
                    if (d[i - 1].find(new_word) != d[i - 1].end()) {
                        dp[word] = max(dp[word], dp[new_word] + 1);
                    }
                }
            }
        }
        int ans = 1;
        for(auto & p : dp) ans = max(ans, p.second);
        return ans;
    }
};
