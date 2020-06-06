class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        // sliding window, O(n)
        int ans = 0, n = s.length();
        unordered_map<char, int> counter;
        int lo = 0;
        for(int hi = 0; hi < n; ++hi) {
            ++counter[s[hi]];
            while (counter.size() > 2) {
                if(--counter[s[lo]] == 0) counter.erase(s[lo]);
                ++lo;
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};
