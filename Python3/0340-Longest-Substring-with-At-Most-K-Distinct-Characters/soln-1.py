class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        # Longest with at most K
        window = collections.Counter()
        lo = 0
        mx = 0
        for i, ch in enumerate(s):
            window[ch] += 1
            while len(window) > k:
                window[s[lo]] -= 1
                if window[s[lo]] == 0:
                    window.pop(s[lo])
                lo += 1
            mx = max(mx, i - lo + 1)
        return mx
