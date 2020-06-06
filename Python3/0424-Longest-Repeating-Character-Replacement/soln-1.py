class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        window = [0] * 26
        A = ord('A')
        mx = 0
        lo = 0
        for i, ch in enumerate(s):
            window[ord(ch) - A] += 1
            while i - lo + 1 - max(window) > k:
                window[ord(s[lo]) - A] -= 1
                lo += 1
            mx = max(mx, i - lo + 1)
        return mx
