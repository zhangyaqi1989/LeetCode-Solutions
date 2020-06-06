class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        n = len(A)
        inc = A[n - 1] > A[0]
        return not any(A[i] != A[i - 1] and ((A[i] > A[i - 1]) != inc) for i in range(1, n))
