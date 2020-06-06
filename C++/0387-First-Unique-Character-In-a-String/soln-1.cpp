class Solution {
public:
    int firstUniqChar(string s) {
        int chars[26] = {0};
        for(char ch : s) ++chars[ch - 'a'];
        int n = s.length();
        for(int i = 0; i < n; ++i)
            if (chars[s[i] - 'a'] == 1) return i;
        return -1;
    }
};
