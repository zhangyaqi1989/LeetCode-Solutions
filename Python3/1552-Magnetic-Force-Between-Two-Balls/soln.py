class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        # minimum force is maximized
        # this is a binary
        def valid(d):
            pre = -math.inf
            idx = 0
            cnt = 0
            for p in position:
                if p - pre >= d:
                    pre = p
                    cnt += 1
                    if cnt == m:
                        return True
            return False
        position.sort()
        lo, hi = 1, position[-1] - position[0]
        while lo < hi:
            mid = hi - (hi - lo) // 2
            if valid(mid):
                lo = mid
            else:
                hi = mid - 1
        return lo
