class Solution:
    def numSubarrayBoundedMax(self, A, L, R):
        """
        :type A: List[int]
        :type L: int
        :type R: int
        :rtype: int
        """
        # mx in [L, R]
        left, right = -1, -1
        cnt = 0
        for i, num in enumerate(A):
            if num > R: left = i
            if num >= L: right = i
            cnt += right - left
        return cnt