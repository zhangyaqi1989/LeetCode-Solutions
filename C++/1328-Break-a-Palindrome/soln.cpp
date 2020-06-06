class Solution {
public:
    string breakPalindrome(string s) {
        const int kN = s.length();
        int idx = 0;
        while (idx < kN / 2) {
            if(s[idx] != 'a') {
                s[idx] = 'a';
                return s;
            }
            ++idx;
        }
        if(s.length() == 1) return "";
        s.back() = 'b';
        return s;
    }
};
