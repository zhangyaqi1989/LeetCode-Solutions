class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        int front = 0, n = s.length();
        for(int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                reverse(&s[front], &s[i]);
                front = i + 1;
            }
        }
        return s.substr(0, s.length() - 1);
    }
};
