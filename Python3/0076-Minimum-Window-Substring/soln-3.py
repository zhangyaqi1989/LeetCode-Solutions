class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # sliding window
        mn = len(s) + 1
        left = 0
        chars = collections.Counter(t)
        lo = 0
        window = collections.Counter()
        valid = False
        for i, c in enumerate(s):
            window[c] += 1
            if not valid:
                if all(window[ch] >= cnt for ch, cnt in chars.items()):
                    valid = True
            if valid:
                while lo < i and window[s[lo]] > chars[s[lo]]:
                    window[s[lo]] -= 1
                    lo += 1
                if i - lo + 1 < mn:
                    mn = i - lo + 1
                    left = lo
                    if mn == len(t):
                        return s[left:left + mn]
        return "" if mn == len(s) + 1 else s[left:left + mn]
