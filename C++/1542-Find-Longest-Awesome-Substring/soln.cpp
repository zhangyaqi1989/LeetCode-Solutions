class Solution {
public:
    int longestAwesome(string s) {
        int mask = 0;
        const int kInf = 1e6;
        vector<int> seen(1 << 10, kInf);
        seen[0] = -1;
        int ans = 1;
        for(int i = 0; i < s.length(); ++i) {
            int idx = s[i] - '0';
            mask ^= (1 << idx);
            ans = max(ans, i - seen[mask]);
            for(int j = 0; j < 10; ++j) {
                int new_mask = mask ^ (1 << j);
                ans = max(ans, i - seen[new_mask]);
            }
            seen[mask] = min(seen[mask], i);
        }
        return ans;
    }
};
