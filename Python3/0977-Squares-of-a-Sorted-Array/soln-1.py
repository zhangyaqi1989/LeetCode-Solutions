class Solution:
    def sortedSquares(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        idx = bisect.bisect_left(A, 0)
        merged = heapq.merge(map(abs, A[:idx][::-1]), A[idx:])
        return [x * x for x in merged]
