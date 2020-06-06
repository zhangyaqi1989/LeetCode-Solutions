class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int ones = count(s.begin(), s.end(), '1');
        int zeros = 0;
        int ans = -1;
        for(int i = 0; i < n - 1; ++i) {
            zeros += s[i] == '0';
            ones -= s[i] == '1';
            ans = max(ans, zeros + ones);
        }
        return ans;
    }
};
