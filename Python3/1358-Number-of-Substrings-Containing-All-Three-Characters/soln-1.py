class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        # sliding window
        window = collections.Counter()
        ans = 0
        lo = 0
        for i, ch in enumerate(s):
            window[ch] += 1
            if len(window) == 3:
                while window[s[lo]] > 1:
                    window[s[lo]] -= 1
                    lo += 1
                ans += lo + 1
        return ans
