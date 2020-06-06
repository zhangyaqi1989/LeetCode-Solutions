class Solution:
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        l, r = 0, len(A) - 1
        while l < r:
            mid = (l + r) >> 1
            if A[mid] < A[mid + 1]:
                l = mid + 1
            else:
                r = mid
        return l