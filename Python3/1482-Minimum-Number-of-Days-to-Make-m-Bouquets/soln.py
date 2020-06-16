class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        def valid(day):
            """check if day is valid."""
            status = [day>= val for val in bloomDay]
            cnt = 0
            for val, g in itertools.groupby(status):
                if val:
                    cnt += len(list(g)) // k
            return cnt >= m
        if len(bloomDay) < m * k:
            return -1
        lo, hi = min(bloomDay), max(bloomDay)
        while lo < hi:
            mid = (lo + hi) >> 1
            if valid(mid):
                hi = mid
            else:
                lo = mid + 1
        return lo if valid(lo) else -1
