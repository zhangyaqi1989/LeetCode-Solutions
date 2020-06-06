class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        # DP[i, j] is s1[:i] and s2[:j] form s3[:i + j]
        # DP[0, 0] = True
        if len(s1) + len(s2) != len(s3):
            return False
        n1, n2 = len(s1), len(s2)
        dp = [[False] * (n2 + 1) for _ in range(n1 + 1)]
        for i in range(0, n1 + 1):
            for j in range(0, n2 + 1):
                if i == 0 and j == 0:
                    dp[i][j] = True
                else:
                    if (i >= 1 and s1[i - 1] == s3[i + j - 1]) and dp[i - 1][j] or (j >= 1 and s2[j - 1] == s3[i + j - 1] and dp[i][j - 1]):
                        dp[i][j] = True   
        return dp[-1][-1]
