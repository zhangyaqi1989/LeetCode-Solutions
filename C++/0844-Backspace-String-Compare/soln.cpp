class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return helper(S) == helper(T);
    }
    
    string helper(string s) {
        vector<char> v;
        for(char ch : s) {
            if (ch == '#') {
                if (!v.empty()) v.pop_back(); 
            } else {
                v.push_back(ch);
            }
        } 
        string ans = "";
        for(char ch : v) ans += ch;
        // cout << ans << endl;
        return ans;
    }
};
