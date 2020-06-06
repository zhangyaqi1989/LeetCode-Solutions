class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        # a typical binary search problem
        def count(num):
            return sum(min(num // x, n) for x in range(1, m + 1))
        lo, hi = 1, m * n
        while lo < hi:
            mid = (hi + lo) >> 1
            if count(mid) < k:
                lo = mid + 1
            else:
                hi = mid
        return lo
