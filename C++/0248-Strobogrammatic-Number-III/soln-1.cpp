
class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        const int mn = low.length(), mx = high.length();
        vector<string> cands = {"00", "11", "88", "69", "96"};
        int cnt = 0;
        dfs("", low, high, cnt, cands);
        dfs("1", low, high, cnt, cands);
        dfs("0", low, high, cnt, cands);
        dfs("8", low, high, cnt, cands);
        return cnt;
    }
    
private:
    void dfs(string cur, const string & low, const string & high, int & cnt, const vector<string> & cands) {
        if (cur.length() > high.length()) return;
        if (valid(cur, low, high)) ++cnt;
        for(string cand : cands) {
            string pre = cand.substr(0, 1), suf = cand.substr(1);
            dfs(pre + cur + suf, low, high, cnt, cands);
        }
    }
    
    bool valid(string cur, const string & low, const string & high) {
        if (cur.length() > 1 && cur[0] == '0') return false;
        if (cur.length() < low.length() || (cur.length() == low.length() && cur < low)) return false;
        if (cur.length() == high.length() && cur > high) return false;
        return true;
    }
    
};
