class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) return 0;
        const int kN = s.length();
        int lo = 0, hi = kN - 1;
        while (lo < hi) {
            if (s[lo] != s[hi]) return 2;
            ++lo;
            --hi;
        }
        return 1;
    }
};
