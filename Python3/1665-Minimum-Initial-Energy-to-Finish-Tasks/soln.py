class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        # minimum effort needed
        lo = sum(actual for actual, min_required in tasks)
        hi = sum(min_required for actual, min_required in tasks)
        max_min_required = max(min_required for _, min_required in tasks)
        lo = max(lo, max_min_required)
        tasks.sort(key=lambda x: (-(x[1] - x[0]), x[0]))
        def valid(initial):
            cur = initial
            for actual, min_required in tasks:
                if cur < min_required:
                    return False
                else:
                    cur -= actual
            return True
        while lo < hi:
            mid = (lo + hi) >> 1
            if valid(mid):
                hi = mid
            else:
                lo = mid + 1
        return lo
