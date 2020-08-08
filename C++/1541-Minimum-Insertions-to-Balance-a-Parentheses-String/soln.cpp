class Solution {
public:
    int minInsertions(string s) {
        const int kN = s.length();
        int nlefts = 0;
        int ans = 0;
        for(int i = 0, j = 0; i < kN; i = j) {
            j = i;
            while(j < kN && s[j] == s[i]) ++j;
            int cnt = j - i;
            if(s[i] == '(') {
                nlefts += cnt;
                continue;
            }
            int nrights = (cnt + 1) / 2;
            if(cnt % 2 == 1) ++ans;
            if(nlefts < nrights) {
                ans += nrights - nlefts;
                nlefts = nrights;
            }
            nlefts -= nrights;
        }
        return 2 * nlefts + ans;
    }
};
