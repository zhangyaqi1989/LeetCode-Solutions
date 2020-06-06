class Solution:
    def longestMountain(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        # B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
        res = up = down = 0
        for i in range(1, len(A)):
            # check whether it is the start of a mountain
            if (down and A[i - 1] <= A[i]) or (A[i - 1] == A[i]): up = down = 0
            up += A[i - 1] < A[i]
            down += A[i - 1] > A[i]
            if up and down: res = max(res, up + down + 1)
        return res