class Solution {
public:
    string removeDuplicateLetters(string s) {
        int ridxes[26];
        memset(ridxes, -1, sizeof ridxes);
        bool inserted[26];
        memset(inserted, false, sizeof inserted);
        int n = s.length();
        string ans = "";
        for(int i = 0; i < n; ++i) ridxes[s[i] - 'a'] = i;
        for(int i = 0; i < n; ++i) {
            char ch = s[i];
            if (!inserted[ch - 'a']) {
                while (!ans.empty() && ch < ans.back() && i < ridxes[ans.back() - 'a']) {
                    inserted[ans.back() - 'a'] = false;
                    ans.pop_back();
                }
                ans += ch;
                inserted[ans.back() - 'a'] = true;
            } 
        }
        return ans;
    }
};
