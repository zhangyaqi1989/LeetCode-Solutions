class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.length() != t.length()) {
            if (s.length() > t.length()) swap(s, t);
            if (t.length() - s.length() > 1) return false;
            int n = s.length();
            for(int i = 0; i < n; ++i) {
                if(s[i] != t[i]) return s.substr(i) == t.substr(i + 1);
            }
            return true;
        } else {
            int n = s.length();
            int cnt = 0;
            for(int i = 0; i < n; ++i) {
                if (s[i] != t[i]) {
                    ++cnt;
                    if (cnt > 1) return false;
                }
            }
            return cnt == 1;
        }
    }
};
