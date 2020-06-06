class Solution {
public:
    int uniqueLetterString(string S) {
        vector<pair<int, int>> idxes(26, {-1, -1});
        long long ans = 0LL;
        int mod = 1000000007;
        int n = S.length();
        for(int idx = 0; idx < n; ++idx) {
            char ch = S[idx];
            auto p = idxes[ch - 'A'];
            int i = p.first, j = p.second;
            ans = (ans + (j - i) * (idx - j)) % mod;
            idxes[ch - 'A'] = {j, idx};
        }
        for(int idx = 0; idx < 26; ++idx) {
            auto p = idxes[idx];
            int i = p.first, j = p.second;
            ans = (ans + (j - i) * (n - j)) % mod;
        }
        return ans;
    }
};
