class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = min(str1.length(), str2.length());
        for(int len = n; len >= 1; --len) {
            string sub = str1.substr(0, len);
            if (divide(str1, sub) && divide(str2, sub)) return sub;
        }
        return "";
    }
    
    bool divide(string s, string sub) {
        int m = s.length(), n = sub.length();
        if (m % n != 0) return false;
        for(int i = 0; i < m; ++i) {
            if (s[i] != sub[i % n]) return false;
        }
        return true;
    }
};
