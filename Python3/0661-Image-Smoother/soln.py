class Solution:
    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        m, n = len(M), len(M[0])
        ans = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                cnt, val = 0, 0
                for di, dj in itertools.product((-1, 0, 1), repeat=2):
                    if 0 <= i + di < m and 0 <= j + dj < n:
                        cnt += 1
                        val += M[i + di][j + dj]
                ans[i][j] = val // cnt
        return ans
