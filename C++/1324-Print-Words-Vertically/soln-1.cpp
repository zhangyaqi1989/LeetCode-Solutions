class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> tokens;
        const int kN = s.length();
        int mx = -1;
        istringstream iss(s);
        string token;
        while (iss >> token) {
            tokens.push_back(token);
            mx = max(mx, (int) token.length());
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
            for(int j = (int) ans[i].size() - 1; j >= 0 && ans[i][j] == ' '; --j) {
                ans[i].pop_back();
            }
        }
        return ans;
    }
};
