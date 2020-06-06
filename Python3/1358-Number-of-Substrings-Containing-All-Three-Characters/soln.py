class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        window = collections.Counter()
        i = 0
        ans = 0
        for j, ch in enumerate(s):
            window[ch] += 1
            if len(window) == 3:
                while window[s[i]] > 1:
                    window[s[i]] -= 1
                    i += 1
                ans += i + 1
        return ans
