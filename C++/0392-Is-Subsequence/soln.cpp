class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size(), m = s.size();
        if (m > n) return false;
        if (m == 0) return true;
        int j = 0;
        for(int i = 0; i < n; ++i) {
            if (t[i] == s[j]) {
                ++j;
                if (j == m) return true;
            }
        }
        return false;
    }
};
