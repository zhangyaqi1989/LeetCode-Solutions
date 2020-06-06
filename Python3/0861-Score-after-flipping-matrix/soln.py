class Solution:
    def matrixScore(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        # toggle each value in a row or column
        # sum of rows intepreted as binary number
        for i, row in enumerate(A):
            if row[0] == 0:
                for j in range(len(row)):
                    row[j] = 1 - row[j]
        ans, m = 0, len(A)
        unit = 2 ** (len(A[0]) - 1)
        for j in range(len(A[0])):
            cnt = sum(A[i][j] == 1 for i in range(m))
            ans += unit * max(cnt, m - cnt)
            unit >>= 1
        return ans