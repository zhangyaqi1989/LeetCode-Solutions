class Solution:
    def prevPermOpt1(self, A: List[int]) -> List[int]:
        n = len(A)
        for j in range(n - 1, 0, -1):
            if A[j] < A[j - 1]:
                for i in range(n - 1, 0, -1):
                    if A[i] < A[j - 1]:
                        A[j - 1], A[i] = A[i], A[j - 1]
                        return A
        return A
