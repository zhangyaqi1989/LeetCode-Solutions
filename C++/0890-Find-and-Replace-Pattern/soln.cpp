class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string np = normalize(pattern);
        vector<string> ans;
        for(string word : words) {
            if (normalize(word) == np)
                ans.push_back(word);
        }
        return ans;
    }
    
    string normalize(string word) {
        map<char, int> m;
        string ans = "";
        for(char ch : word) {
            if (m.find(ch) == m.end()) m[ch] = m.size();
            ans += ('a' + m[ch]);
        }
        return ans;
    }
};
