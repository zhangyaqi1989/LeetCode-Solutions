class Solution {
public:
    vector<string> expand(string S) {
        vector<vector<string>> groups;
        const int n = S.length();
        for(int i = 0; i < n; ++i) {
            groups.push_back({});
            if (S[i] == '{') {
                int lo = i + 1;
                int hi = lo;
                while(hi < n && S[hi] != '}') ++hi;
                string g = S.substr(lo, hi - lo);
                int m = g.length();
                lo = 0;
                for(int j = 0; j < m; ++j) {
                    if (g[j] == ',') {
                        groups.back().push_back(g.substr(lo, j - lo));
                        lo = j + 1;
                    }
                }
                groups.back().push_back(g.substr(lo, m - lo));
                i = hi;
            } else {
                string token;
                while(i < n && isalpha(S[i])) token += S[i++];
                --i;
                groups.back().push_back(token);
            }
        }
        vector<string> ans;
        dfs(0, groups, "", ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
private:
    void dfs(int idx, const vector<vector<string>> & groups, string cand, vector<string> & ans) {
            if (idx == groups.size()) {
                ans.push_back(cand);
            } else {
                for(string nxt : groups[idx]) {
                    dfs(idx + 1, groups, cand + nxt, ans);
                }
            }
        }
};
