class Solution:
    def minWindow(self, S: str, T: str) -> str:
        ns, nt = len(S), len(T)
        dp = [[-1] * (ns + 1) for _ in range(nt + 1)]
        # dp[i][j] is left index of substring in S[:j] that contains T[:i]
        for j in range(ns + 1):
            dp[0][j] = j
        for i in range(1, nt + 1):
            for j in range(1, ns + 1):
                if T[i - 1] == S[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = dp[i][j - 1]
        start, l = 0, len(S) + 1
        for j in range(ns + 1):
            if dp[-1][j] != -1:
                if j - dp[-1][j] < l or (j - dp[-1][j] == l and dp[-1][j] < start):
                    start = dp[-1][j]
                    l = j - dp[-1][j]
        return "" if l == len(S) + 1 else S[start:start + l]
