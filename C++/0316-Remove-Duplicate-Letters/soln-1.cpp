class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last [26] = {0};
        const int n = s.length();
        for(int i = 0; i < n; ++i) last[s[i] - 'a'] = i;
        bool isin[26] = {0};
        string ans;
        for(int i = 0; i < n; ++i) {
            if(!isin[s[i] - 'a']) {
                while (!ans.empty() && s[i] < ans.back() && last[ans.back() - 'a'] > i) {
                    isin[ans.back() - 'a'] = false;
                    ans.pop_back();
                }
                ans.push_back(s[i]);
                isin[s[i] - 'a'] = true;
            }
        }
        return ans;
    }
};
