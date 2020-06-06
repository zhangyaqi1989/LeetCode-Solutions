ass Solution:
    def sortedSquares(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        n = len(A)
        ans = [0] * n
        i, j = 0, n - 1
        for idx in reversed(range(n)):
            if abs(A[i]) > abs(A[j]):
                ans[idx] = A[i] * A[i]
                i += 1
            else:
                ans[idx] = A[j] * A[j]
                j -= 1
        return ans
