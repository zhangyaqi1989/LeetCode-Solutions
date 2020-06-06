class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // sliding window, O(n)
        int ans = 0, n = s.length();
        unordered_map<char, int> counter;
        int lo = 0;
        for(int hi = 0; hi < n; ++hi) {
            ++counter[s[hi]];
            while (counter.size() > k) {
                if(--counter[s[lo]] == 0) counter.erase(s[lo]);
                ++lo;
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;        
    }
};
