import functools, operator
class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        lo, hi = 1, 2 * 1000000000
        a, b, c = sorted([a, b, c])
        
        def count(num):
            return num // a + num // b + num // c - num // (a * b // math.gcd(a, b)) - num // (a * c // math.gcd(a, c)) - num // (b * c // math.gcd(b, c)) + num // (a * b * c // (max( math.gcd(a, b) * math.gcd(b, c), math.gcd(a, c) * math.gcd(b, c), math.gcd(a, b) * math.gcd(a, c)) )  )
        
        while lo < hi:
            mid = (lo + hi) >> 1
            cnt = count(mid)
            if cnt < n:
                lo = mid + 1
            else:
                hi = mid
        return lo
