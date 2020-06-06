class Solution:
    def preimageSizeFZF(self, K: int) -> int:
        def count(num):
            cnt = 0
            while num:
                cnt += num // 5
                num //= 5
            return cnt
        lo, hi = 0, 2 ** 63 - 1
        while lo < hi:
            mid = (lo + hi) >> 1
            if count(mid) < K:
                lo = mid + 1
            else:
                hi = mid
        return 5 - lo % 5 if count(lo) == K else 0
