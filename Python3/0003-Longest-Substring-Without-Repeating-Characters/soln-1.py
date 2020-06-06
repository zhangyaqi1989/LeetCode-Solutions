class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # need to know last seen ch
        last_seen = {}
        mx = 0
        lo = -1
        for i, ch in enumerate(s):
            lo = max(lo, last_seen.get(ch, -1))
            mx = max(mx, i - lo)
            last_seen[ch] = i
        return mx
