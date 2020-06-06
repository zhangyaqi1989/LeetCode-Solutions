class Solution:
    def hIndex(self, citations: List[int]) -> int:
        if not citations:
            return 0
        citations.sort(reverse=True)
        if citations[-1] >= len(citations):
            return len(citations)
        if citations[0] == 0:
            return 0
        lo, hi = 0, len(citations) - 1
        while lo < hi:
            mid = hi - (hi - lo) // 2
            if citations[mid] < mid + 1:
                hi = mid - 1
            else:
                lo = mid
        return lo + 1
