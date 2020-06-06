class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        string ans = "";
        unordered_set<string> s;
        for(string word : words) {
            if (word.length() == 1 || s.find(word.substr(0, word.length() - 1)) != s.end()) {
                if (word.length() > ans.length()) ans = word;
                s.insert(word);
            }
        }
        return ans;
    }
};
