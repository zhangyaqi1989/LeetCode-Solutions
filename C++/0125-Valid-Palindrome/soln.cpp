class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int n = s.length();
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) ++i;
            while (i < j && !isalnum(s[j])) --j;
            if (i < j) {
                if (s[i] != s[j]) return false;
                ++i;
                --j;
            }
        }
        return true;
    }
};
