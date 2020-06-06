class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int chars[26] = {0};
        for(char ch : magazine) ++chars[ch - 'a'];
        for(char ch : ransomNote) {
            if (--chars[ch - 'a'] < 0) return false;
        }
        return true;
    }
};
