class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        string rs1(s1);
        sort(rs1.begin(), rs1.end());
        string rs2(s2);
        sort(rs2.begin(), rs2.end());
        if (rs1 != rs2) return false;
        int n = s1.length();
        for(int i = 1; i < n; ++i) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) || (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i))))
                return true;
        }
        return false;
    }
};
