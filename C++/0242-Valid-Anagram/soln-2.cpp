class Solution {
public:
    bool isAnagram(string s, string t) {
        int chars[26] = {0};
        for(char ch : s) ++chars[ch - 'a'];
        for(char ch : t) --chars[ch - 'a'];
        for(int i = 0; i < 26; ++i) 
            if (chars[i] != 0)
                return false;
        return true;
    }
};
