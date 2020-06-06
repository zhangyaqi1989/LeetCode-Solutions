class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        ab = (a * b) // math.gcd(a, b)
        ac = (a * c) // math.gcd(a, c)
        bc = (b * c) // math.gcd(b, c)
        abc = (ab * c) // math.gcd(ab, c)
        lo, hi = 1, 2 * 10 ** 9
        while lo < hi:
            mid = (lo + hi) >> 1
            count = mid // a + mid // b + mid // c - mid // ab - mid // ac - mid // bc + mid // abc;
            if count < n:
                lo = mid + 1
            else:
                hi = mid
        return lo
