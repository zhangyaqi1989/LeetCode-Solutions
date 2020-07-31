class Solution:
    def twoSumLessThanK(self, A: List[int], K: int) -> int:
        n = len(A)
        return max([A[i] + A[j] for i in range(n) for j in range(i + 1, n) if A[i] + A[j] < K] or [-1])
