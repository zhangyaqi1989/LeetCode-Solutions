class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        def compute_days(C):
            cur = days = 0
            for weight in weights:
                if cur + weight > C:
                    days += 1
                    cur = weight
                else:
                    cur += weight
            return days + 1
        lo, hi = max(weights), sum(weights)
        while lo < hi:
            mid = (lo + hi) >> 1
            days = compute_days(mid)
            if days > D:
                lo = mid + 1
            else:
                hi = mid
        return lo
