class Solution {
public:
    string addBoldTag(string S, vector<string>& words) {
        int n = S.length();
        vector<bool> tags(n, false);
        for(string & word : words) {
            int m = word.length();
            for(int i = 0; i < n - m + 1; ++i) {
                if (S.substr(i, m) == word) {
                    for(int j = i; j < i + m; ++j) tags[j] = true;
                }
            }
        }
        string ans = "";
        for(int i = 0; i < n; ++i) {
            char ch = S[i];
            if (tags[i] && (i == 0 || !tags[i - 1])) ans += "<b>";
            ans += ch;
            if (tags[i] && (i == n - 1 || !tags[i + 1])) ans += "</b>";
        }
        return ans;        
    }
};
