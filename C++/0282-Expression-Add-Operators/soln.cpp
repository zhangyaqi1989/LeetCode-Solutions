class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        for(int i = 1; i <= num.length(); ++i) {
            if (i > 1 && num[0] == '0') continue;
            long long val = stoll(num.substr(0, i));
            dfs(num, i, num.substr(0, i), val, val, target, ans);
        }
        return ans;
    }
    
    void dfs(string & num, int idx, string expr, long long cur, long long last, int target, vector<string> & ans) {
        if (idx == num.length()) {
            if (cur == target) ans.push_back(expr);
        } else {
            for(int i = idx + 1; i <= num.length(); ++i) {
                if (i - idx > 1 && num[idx] == '0') continue;
                string nxt = num.substr(idx, i - idx);
                long long val = stoll(nxt);
                dfs(num, i, expr + "+" + nxt, cur + val, val, target, ans);
                dfs(num, i, expr + "-" + nxt, cur - val, -val, target, ans);
                dfs(num, i, expr + "*" + nxt, cur - last + last * val, last * val, target, ans);
            }
        }
    }
};
