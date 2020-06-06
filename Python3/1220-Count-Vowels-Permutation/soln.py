class Solution:
    def countVowelPermutation(self, n: int) -> int:
        # ae
        # ei, ea
        # ia, ie, io, iu
        # oi, ou
        # ua
        mod = 1000000007
        a = e = i = o = u = 1
        for _ in range(1, n):
            a, e, i, o, u = (e + i + u) % mod, (a + i) % mod, (e + o) % mod, i, (i + o) % mod
        return (a + e + i + o + u) % mod
