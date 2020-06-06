class Solution:
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        return next(itertools.islice(heapq.merge(*matrix), k - 1, k))