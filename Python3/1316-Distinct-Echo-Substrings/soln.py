class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        P = 31
        mod = 1000000009
        n = len(text)
        ps = [1]
        for i in range(1, n):
            ps.append(ps[-1] * P % mod)
        hs = [0]
        for i, ch in enumerate(text):
            hs.append((hs[-1] + (ord(ch) - ord('a')) * ps[i]) % mod)
        ans = 0
        for l in range(1, n // 2 + 1):
            seen = set()
            for i in range(n - 2 * l + 1):
                # [i, i + l) and [i + l, i + 2 * l)
                a = (hs[i + l] + mod - hs[i]) % mod
                b = (hs[i + 2 * l] + mod - hs[i + l]) % mod
                a = (a * ps[n - 1 - i]) % mod
                b = (b * ps[n - 1 - i - l]) % mod
                if a == b:
                    seen.add(a)
            ans += len(seen)
        return ans
