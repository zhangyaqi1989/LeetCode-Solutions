class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        lo, hi = 0, len(A) - 1
        while lo < hi:
            mid = (lo + hi) >> 1
            if A[mid] < A[mid + 1]:
                lo = mid + 1
            else:
                hi = mid
        return lo
