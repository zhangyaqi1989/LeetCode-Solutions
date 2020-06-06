class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        # maximum number
        vowels = "AEIOUaeiou"
        window = 0
        n = len(s)
        mx = 0
        for i, ch in enumerate(s):
            # print(ch in vowels)
            window += (ch in vowels)
            if i >= k:
                window -= (s[i - k] in vowels)
            if i >= k - 1:
                mx = max(mx, window)
            # print(window)
        return mx
