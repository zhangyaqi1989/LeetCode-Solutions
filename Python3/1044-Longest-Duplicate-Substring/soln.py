import functools
class Solution:
    def longestDupSubstring(self, S: str) -> str:
        # hash
        A = [ord(ch) - ord('a') for ch in S]
        mod = (1 << 63) - 1
        def valid(L):
            cur = functools.reduce(lambda x , y : (x * 26 + y) % mod, A[:L], 0)
            seen = {cur}
            n = len(A)
            high_unit = pow(26, L, mod)
            for i in range(L, n):
                cur = (cur * 26 + A[i] - A[i - L] * high_unit) % mod
                if cur in seen:
                    return i - L + 1
                seen.add(cur)
            return -1
        lo, hi = 0, len(S)
        res = 0
        while lo < hi:
            mid = hi - (hi - lo) // 2
            p = valid(mid)
            if p != -1:
                lo = mid
                res = p
            else:
                hi = mid - 1
        return S[res:lo + res]
