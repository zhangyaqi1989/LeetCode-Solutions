const vector<pair<string, string>> pairs = {{"0", "0"}, {"1", "1"}, {"8", "8"}, {"6", "9"}, {"9", "6"}};
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> ans;
        if (n % 2 == 1) {
            dfs(n, "0", & ans);
            dfs(n, "1", & ans);
            dfs(n, "8", & ans);
        } else {
            dfs(n, "", & ans);
        }
        return ans;
    }
    
private:
    void dfs(int n, string s, vector<string> * ans) {
        const int kN = s.length();
        if (kN == n) {
            if (!(kN > 1 && s[0] == '0')) ans->push_back(s);
        } else if (kN < n) {
            for(auto p : pairs) {
                dfs(n, p.first + s + p.second, ans);
            }
        }
    }
};
