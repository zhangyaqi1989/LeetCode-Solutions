class Solution {
public:
    int numSub(string s) {
        const int kN = s.length();
        int ans = 0;
        const int kMod = 1000000007;
        for(int i = 0, j; i < kN; i = j) {
            j = i;
            while(j < kN && s[j] == s[i]) {
                ++j;
            }
            if(s[i] == '1') {
                int len = j - i;
                ans = (ans + ((long long) (len + 1) * len) / 2) % kMod;
            }
        }
        return ans;
    }
};
