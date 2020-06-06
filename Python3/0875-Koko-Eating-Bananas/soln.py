class Solution:
    def minEatingSpeed(self, piles, H):
        """
        :type piles: List[int]
        :type H: int
        :rtype: int
        """
        # minimum K
        def time(K):
            return sum((pile + K - 1) // K for pile in piles)
        lo, hi = 1, max(piles)
        while lo < hi:
            mid = (lo + hi) >> 1
            t = time(mid)
            if t > H:
                lo = mid + 1
            else:
                hi = mid
        return lo
