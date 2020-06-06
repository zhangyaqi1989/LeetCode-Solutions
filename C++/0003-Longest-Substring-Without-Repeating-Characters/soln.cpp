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
        unordered_map<char, int> seen;
        for(int hi = 0; hi < s.size(); ++hi) {
            char ch = s[hi];
            if (seen.find(ch) != seen.end()) lo = max(lo, seen[ch]);
            seen[ch] = hi;
            ans = max(ans, hi - lo);
        }
        return ans;
    }
};
