auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// ALG: substring
// two pointer lo, hi

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lo = -1;
        int ans = 0;
        int seen[256];
        memset(seen, -1, sizeof(seen));
        for(int hi = 0; hi < s.size(); ++hi) {
            char ch = s[hi];
            if (seen[ch] != -1) lo = max(lo, seen[ch]);
            seen[ch] = hi;
            ans = max(ans, hi - lo);
        }
        return ans;
    }
};
