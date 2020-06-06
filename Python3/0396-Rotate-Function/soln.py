class Solution:
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        f = sum(i * num for i, num in enumerate(A))
        s = sum(A)
        mx = f
        for i in reversed(range(1, n)):
            f = f + s - n * A[i]
            if f > mx:
                mx = f
        return mx
