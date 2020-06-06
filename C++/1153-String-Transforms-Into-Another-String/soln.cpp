class Solution {
public:
    bool canConvert(string str1, string str2) {
        
        vector<int> chars(26, -1);
        const int n = str1.size();
        for(int i = 0; i < n; ++i) {
            if (str1[i] != str2[i]) {
                if (chars[str1[i] - 'a'] == -1) {
                    chars[str1[i] - 'a'] = str2[i] - 'a';
                } else {
                    if (chars[str1[i] - 'a'] != str2[i] - 'a') return false;
                }
            }
        }
        if (str1 == str2) return true;
        unordered_set<char> s2(str2.begin(), str2.end());
        return s2.size() != 26;
    }
};
