class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        def count(m, n, num):
            # count number of numbers that is less than num in the table
            return sum(min(n, num // factor) for factor in range(1, m + 1))
        lo, hi = 1, m * n
        while lo < hi:
            mid = (lo + hi) >> 1
            cnt = count(m, n, mid)
            if cnt < k:
                lo = mid + 1
            else:
                hi = mid
        return lo
