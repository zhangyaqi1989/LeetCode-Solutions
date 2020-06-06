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
            mid = (lo + hi) >> 1
            if citations[mid] >= mid + 1 and citations[mid + 1] < mid + 2:
                return mid + 1
            elif citations[mid] < mid + 1:
                hi = mid - 1
            else:
                lo = mid + 1
        return lo + 1
