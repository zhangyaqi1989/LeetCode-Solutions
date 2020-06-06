class Solution:
    def longestLine(self, M: List[List[int]]) -> int:
        if not any(M):
            return 0
        m, n = len(M), len(M[0])
        ans = 0
        mxs = [[[0, 0, 0, 0] for j in range(n)] for i in range(m)]
        for i in range(m):
            for j in range(n):
                if M[i][j] == 1:
                    mxs[i][j] = [1] * 4
                    if i > 0:
                        mxs[i][j][0] = 1 + mxs[i - 1][j][0]
                    if j > 0:
                        mxs[i][j][1] = max(1 + mxs[i][j - 1][1], mxs[i][j][1])
                    if i > 0 and j > 0:
                        mxs[i][j][2] = max(1 + mxs[i - 1][j - 1][2], mxs[i][j][2])
                    if i > 0 and j < n - 1:
                        mxs[i][j][3] = max(1 + mxs[i - 1][j + 1][3], mxs[i][j][3])
                    ans = max(ans, max(mxs[i][j]))
        return ans
