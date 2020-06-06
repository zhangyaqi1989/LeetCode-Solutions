class Solution {
private:
    unordered_map<string, bool> memo;
public:
    bool canWin(string s) {
        memo.clear();
        return helper(s);
    }
    
    bool helper(string s) {
        if (s.find("++") == string::npos) return false;
        auto it = memo.find(s);
        if (it != memo.end()) return it->second;
        int i = 0, n = s.length();
        bool res = false;
        while (i < n) {
            int j = s.find("++", i);
            if (j == string::npos) break;
            string new_s(s);
            new_s[j] = '-';
            new_s[j + 1] = '-';
            if (!helper(new_s)) {
                res = true;
                break;
            }
            i = j + 1;
        }
        memo[s] = res;
        return res;
    }
};
