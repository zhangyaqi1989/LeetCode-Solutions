class Solution:
    def shortestCommonSupersequence(self, A: str, B: str) -> str:
        m, n = len(A), len(B)
        dp = [[""] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if A[i - 1] == B[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + A[i - 1]
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], key=len)
        lcs = dp[-1][-1]
        i, j = 0, 0
        res = []
        for ch in lcs:
            while i < m and A[i] != ch:
                res.append(A[i])
                i += 1
            while j < n and B[j] != ch:
                res.append(B[j])
                j += 1
            i += 1
            j += 1
            res.append(ch)
        return ''.join(res) + A[i:] + B[j:]
