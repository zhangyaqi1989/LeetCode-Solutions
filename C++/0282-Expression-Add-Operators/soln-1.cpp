class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        const int n = num.length();
        string prefix;
        for(int i = 0; i < n; ++i) {
            prefix += num[i];
            if (prefix.length() > 1 && prefix[0] == '0') break;
            dfs(i + 1, stol(prefix), stol(prefix), num, prefix, target, ans);
        }
        return ans;
    }
    
private:
    void dfs(int idx, long cur, long last, const string & s, string exp, int target, vector<string> & ans) {
        const int n = s.length();
        if (idx == n) {
            if (cur == target) {
                ans.push_back(exp);
            }
        } else {
            for(int j = idx + 1; j <= n; ++j) {
                string nxt = s.substr(idx, j - idx);
                if (nxt.length() > 1 && nxt[0] == '0') break;
                long nxt_val = stol(nxt);
                dfs(j, cur + nxt_val, nxt_val, s, exp + "+" + nxt, target, ans);
                dfs(j, cur - nxt_val, -nxt_val, s, exp + "-" + nxt, target, ans);
                dfs(j, cur - last + last * nxt_val, nxt_val * last, s, exp + "*" + nxt, target, ans);
            }
        }
    }
};
