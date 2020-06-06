class Solution {
public:
    int longestDecomposition(string text) {
        return helper(text, 0, (int) text.length() - 1);
    }
    
    int helper(string & text, int lo, int hi) {
        if (lo == hi) return 1;
        else if (lo > hi) return 0;
        else {
            for(int len = 1; len <= (hi - lo + 1) / 2; ++len) {
                if (text.substr(lo, len) == text.substr(hi - len + 1, len)) {
                    return 2 + helper(text, lo + len, hi - len);
                }
            }
            return 1;
        }
    }
};
