class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        # at most two distinct characters
        window = collections.Counter()
        mx = 0
        lo = 0
        for i, ch in enumerate(s):
            window[ch] += 1
            while len(window) > 2:
                window[s[lo]] -= 1
                if window[s[lo]] == 0:
                    window.pop(s[lo])
                lo += 1
            mx = max(mx, i - lo + 1)
        return mx
