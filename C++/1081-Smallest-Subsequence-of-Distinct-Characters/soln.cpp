class Solution {
public:
    string smallestSubsequence(string text) {
        string ans = "";
        int last[26] = {0};
        int n = text.length();
        for(int i = 0; i < n; ++i) last[text[i] - 'a'] = i;
        bool used[26] = {0};
        for(int i = 0; i < n; ++i) {
            char ch = text[i];
            if (!used[ch - 'a']) {
                while (!ans.empty() && ch < ans.back() && i < last[ans.back() - 'a']) {
                    used[ans.back() - 'a'] = false;
                    ans.pop_back();
                }
                ans += ch;
                used[ch - 'a'] = true;
            }
        }
        return ans;
    }
};
