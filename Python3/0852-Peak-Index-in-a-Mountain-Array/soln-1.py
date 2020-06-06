class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        lo, hi = 0, len(A) - 1
        while lo < hi:
            mid = hi - (hi - lo) // 2
            if A[mid] > A[mid - 1]:
                lo = mid
            else:
                hi = mid - 1
        return lo
