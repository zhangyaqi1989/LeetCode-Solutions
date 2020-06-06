class Solution {
public:
    string reverseWords(string s) {
        vector<string> tokens;
        int idx = 0;
        int n = s.length();
        while(idx < n) {
            if(s[idx] == ' ') {
                ++idx;
                continue;
            } else{
                string token;
                while(idx < n && s[idx] != ' ') {
                    token += s[idx++];
                }
                tokens.push_back(token);
            }
        }
        int m = tokens.size();
        string ans;
        for(int i = m - 1; i >= 0; --i) {
            ans += tokens[i];
            if(i != 0) ans += " ";
        }
        return ans;
    }
};
