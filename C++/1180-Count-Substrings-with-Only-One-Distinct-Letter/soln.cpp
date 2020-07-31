class Solution {
public:
    int countLetters(string S) {
        int n = S.length();
        int ans = 0;
        for(int i = 0; i < n;) {
            int j = i;
            while(j < n && S[j] == S[i]) ++j;
            int cnt = j - i;
            ans += (1 + cnt) * cnt / 2;
            i = j;
        }
        return ans;
    }
};
