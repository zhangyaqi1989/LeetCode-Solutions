class Solution:
    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        mA, nA, nB = len(A), len(A[0]), len(B[0])
        res = [[0] * nB for _ in range(mA)]
        for i in range(mA):
            for j in range(nA):
                if A[i][j]:
                    for k in range(nB):
                        res[i][k] += A[i][j] * B[j][k]
        return res