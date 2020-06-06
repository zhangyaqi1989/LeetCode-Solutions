class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> tokens;
        const int kN = s.length();
        int mx = -1;
        for(int i = 0; i < kN;) {
            auto j = s.find(' ', i);
            if (j == string::npos) j = kN;
            mx = max(mx, (int) j - i);
            tokens.push_back(s.substr(i, j - i));
            i = j + 1;
        }
        const int kM = tokens.size();
        vector<string> ans(mx);
        for(int i = 0; i < mx; ++i) {
            for(int j = 0; j < kM; ++j) {
                if (i < (int) tokens[j].size()) ans[i] += tokens[j][i];
                else ans[i] += ' ';
            }
        }
        for(int i = 0; i < mx; ++i) {
            int j = ans[i].size() - 1;
            while (j >= 0 && ans[i][j] == ' ') {
                ans[i].pop_back();
                --j;
            }
        }
        return ans;
    }
};
