class Solution {
public:
    char findTheDifference(string s, string t) {
        int chars[26] = {0};
        for(char ch : s) ++chars[ch - 'a'];
        for(char ch : t) {
            if (chars[ch - 'a']-- == 0) return ch;
        }
        return ' ';
    }
};
