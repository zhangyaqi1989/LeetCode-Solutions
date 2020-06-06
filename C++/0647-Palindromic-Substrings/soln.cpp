class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            cnt += helper(s, i, i);
            cnt += helper(s, i, i + 1);
        }
        return cnt;
    }
    
    int helper(string & s, int i, int j) {
        int n = s.length();
        while(i >= 0 && j < n && s[i] == s[j]) {
            --i;
            ++j;
        }
        return (j - (i + 1) + 1) / 2;
    }
};
