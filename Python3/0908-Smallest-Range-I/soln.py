class Solution:
    def smallestRangeI(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        mn, mx = min(A), max(A)
        return max(0, mx - mn - 2 * K)