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
        vector<int> m(256, -1);
        string ans = "";
        int size = 0;
        for(char ch : word) {
            if (m[ch] == -1) {
                m[ch] = size++;
            }
            ans += (m[ch]);
        }
        return ans;
    }
};
