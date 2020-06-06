class Solution:
    def largestOverlap(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: int
        """
        # square matrixes
        n = len(A)
        a, b = [], []
        d = collections.Counter()
        for i in range(n):
            for j in range(n):
                if A[i][j]:
                    a.append((i, j))
                if B[i][j]:
                    b.append((i, j))
        for (ia, ja), (ib, jb) in itertools.product(a, b):
            d[(ia - ib, ja - jb)] += 1
        return d.most_common(1)[0][1] if d else 0