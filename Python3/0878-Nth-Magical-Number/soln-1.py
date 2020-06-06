class Solution:
    def nthMagicalNumber(self, N: int, A: int, B: int) -> int:
        gcd = math.gcd(A, B)
        lcm = A * B // gcd
        lo, hi = min(A, B), min(A, B) * N
        while lo < hi:
            mid = (lo + hi) >> 1
            cnt = mid // A + mid // B - mid // lcm
            if cnt < N:
                lo = mid + 1
            else:
                hi = mid
        return lo % (1000000007)
