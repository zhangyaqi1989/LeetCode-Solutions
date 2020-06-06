class Solution:
    def smallestRangeII(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        # + 0 or 2 * K
        # to which index: add 2 * K
        A.sort()
        res = A[-1] - A[0]
        for i in range(0, len(A) - 1):
            mn = min(A[0] + 2 * K, A[i + 1])
            mx = max(A[-1], A[i] + 2 * K)
            res = min(res, mx - mn)
        return res