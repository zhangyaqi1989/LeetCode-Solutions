class Solution:
    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n, nA = len(A), len(B[0]), len(A[0])
        C = [[0] * n for _ in range(m)]
        for i in range(m):
            for k in range(nA):
                if A[i][k] != 0:
                    for j in range(n):
                        if B[k][j] != 0:
                            C[i][j] += A[i][k] * B[k][j]
        return C
