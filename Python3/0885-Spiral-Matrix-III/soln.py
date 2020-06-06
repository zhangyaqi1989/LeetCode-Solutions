class Solution:
    def spiralMatrixIII(self, R, C, r0, c0):
        """
        :type R: int
        :type C: int
        :type r0: int
        :type c0: int
        :rtype: List[List[int]]
        """
        # 11223344
        ans = [[r0, c0]]
        x, y, n, i = 0, 1, 0, 0
        while len(ans) < R * C:
            r0, c0, i = r0 + x, c0 + y, i + 1
            if 0 <= r0 < R and 0 <= c0 < C:
                ans.append([r0, c0])
            if i == n // 2 + 1:
                x, y, n, i = y, -x, n + 1, 0
        return ans