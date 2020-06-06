class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int zeros = 0;
        for(char ch : S) {
            if (ch == '0') ++zeros;
        }
        int n = S.length();
        int ans = n;
        int left_zeros = 0;
        for(int i = 0; i <= n; ++i) {
            int modifies = i - left_zeros + (zeros - left_zeros);
            if (i < n && S[i] == '0') ++left_zeros; 
            ans = min(ans, modifies);
            // cout << ans << endl;
        }
        return ans;
    }
};
