class Solution {
public:
    string encode(string s) {
        memo.clear();
        return helper(s);
    }
    
    string helper(string s) {
        if (s.empty()) return "";
        auto it = memo.find(s);
        if (it != memo.end()) return (*it).second;
        int i = (s + s).find(s, 1);
        int n = s.length();
        string one = i < n ? to_string(n / i) + "[" + helper(s.substr(0, i)) + "]": s;
        string ans = one.length() < n ? one : s;
        for(int i = 1; i < n; ++i) {
            string temp = helper(s.substr(0, i)) + helper(s.substr(i));
            if (temp.length() < ans.length()) ans = temp; 
        }
        memo[s] = ans;
        return ans;        
    }
    
private:
    unordered_map<string, string> memo;
};
