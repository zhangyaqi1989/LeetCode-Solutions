class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        string ss = (s + s).substr(1, 2 * n - 2);
        return ss.find(s) != string::npos;
    }
};
