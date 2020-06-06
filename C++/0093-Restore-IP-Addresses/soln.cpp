class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string cand = "";
        dfs(s, 0, 0, cand, ans);
        return ans;
    }
    void dfs(const string & s, int idx, int cnt, string & cand, vector<string> & ans) {
        if (cnt == 4) {
            if (idx == s.length()) {
                cand.pop_back();
                ans.push_back(cand);                
            }
        } else if (cnt < 4) {
            for(int i = idx + 1; i <= min((int) s.length(), idx + 3); ++i) {
                if (i - idx > 1 && s[idx] == '0') break;
                string nxt = s.substr(idx, i - idx);
                int nxt_num = stoi(nxt);
                if (nxt_num <= 255) {
                    int pre_length = cand.length();
                    cand += nxt + ".";
                    dfs(s, i, cnt + 1, cand, ans);
                    cand.resize(pre_length);
                }
            }
        }
    }
};
