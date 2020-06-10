class Solution {
public:
    bool isAnagram(string s, string t) {
        int schars[26] = {0};
        int tchars[26] = {0};
        for(char ch : s) ++schars[ch - 'a'];
        for(char ch : t) ++tchars[ch - 'a'];
        for(int i = 0; i < 26; ++i) {
            if (schars[i] != tchars[i]) return false;
        }
        return true;
    }
};
