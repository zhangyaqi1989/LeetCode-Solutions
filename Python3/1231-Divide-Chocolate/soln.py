class Solution:
    def maximizeSweetness(self, sweetness: List[int], K: int) -> int:
        def check(swt):
            cnt = 0
            cur = 0
            for x in sweetness:
                if cur < swt:
                    cur += x
                else:
                    cnt += 1
                    cur = x
            if cur >= swt:
                cnt += 1
            return cnt >= K + 1
        lo, hi = min(sweetness), sum(sweetness)
        while lo < hi:
            mid = hi - (hi - lo) // 2
            if not check(mid):
                hi = mid - 1
            else:
                lo = mid
        return lo
