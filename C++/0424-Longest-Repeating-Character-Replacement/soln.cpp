class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), lo = 0, ans = 0;
        int cnts[91] = {0};
        for(int hi = 0; hi < n; ++hi) {
            ++cnts[s[hi]];
            while (hi - lo + 1 - *max_element(cnts + 65, cnts + 91) > k) {
                --cnts[s[lo++]];
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};
