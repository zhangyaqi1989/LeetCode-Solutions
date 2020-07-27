class Solution:
    def getLengthOfOptimalCompression(self, s: str, k: int) -> int:
        @lru_cache(None)
        def dp(start, last, cnt, left):
            if left < 0:
                return math.inf
            if start >= len(s):
                return 0
            if last == s[start]:
                inc = 1 if cnt in (1, 9, 99) else 0
                return inc + dp(start + 1, last, cnt + 1, left)
            else:
                return min(1 + dp(start + 1, s[start], 1, left), dp(start + 1, last, cnt, left - 1))
        return dp(0, "", 0, k)
