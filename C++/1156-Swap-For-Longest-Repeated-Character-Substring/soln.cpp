class Solution {
public:
    int maxRepOpt1(string text) {
        vector<vector<pair<int, int>>> idxes(26);
        const int kN = text.length();
        for(int i = 0, j = 0; i < kN; i = j) {
            j = i;
            while(j < kN && text[j] == text[i]) ++j;
            int cnt = j - i;
            idxes[text[i] - 'a'].emplace_back(i, j);
        }
        int ans = 0;
        for(int i = 0; i < 26; ++i) {
            int n = idxes[i].size();
            for(const auto & interval : idxes[i]) {
                auto [s, e] = interval;
                ans = max(ans, (n > 1 ? 1 : 0) + e - s);
            }
            for(int j = 1; j < n; ++j) {
                auto [s1, e1] = idxes[i][j - 1];
                auto [s2, e2] = idxes[i][j];
                if(e1 + 1 == s2) {
                    ans = max(ans, (n > 2 ? 1 : 0) + e1 - s1 + e2 - s2);
                }
            }
        }
        return ans;
    }
};
