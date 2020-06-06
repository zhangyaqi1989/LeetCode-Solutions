class Solution {
public:
    int maxPower(string s) {
        int lo = 0;
        int n = s.length();
        int mx = 1;
        for(int i = 0; i < n; ++i) {
            if(s[i] != s[lo]) {
                mx = max(mx, i - lo);
                lo = i;
            }
        }
        return max(mx, n - lo);
    }
};
