class Solution:
    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        def dot(v1, v2):
            return sum(a * b for a, b in zip(v1, v2))
        m, n = len(A), len(B[0])
        B = list(zip(*B))
        return [[dot(A[i], B[j]) for j in range(n)] for i in range(m)] 