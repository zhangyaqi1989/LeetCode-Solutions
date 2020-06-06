class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        --n;
        while (n >= 0 && isspace(s[n])) {
            --n;
        }
        int i = n;
        while (i >= 0 && !isspace(s[i])) {
            --i;
        }
        return n - i;
    }
};
