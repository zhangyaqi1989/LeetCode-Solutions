class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            if (s[lo] != s[hi]) {
                return isPalindrome(s.substr(lo + 1, hi - lo)) || isPalindrome(s.substr(lo, hi - lo));
            }
            ++lo;
            --hi;
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        int n = s.length();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            if (s[lo] != s[hi])
                return false;
            ++lo;
            --hi;
        }
        return true;
    }
};
