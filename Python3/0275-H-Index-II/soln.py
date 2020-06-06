class Solution:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        lo, hi = 0, n
        while lo < hi:
            mid = (lo + hi) >> 1
            if citations[mid] >= n - mid:
                hi = mid
            else:
                lo = mid + 1
        return n - lo
