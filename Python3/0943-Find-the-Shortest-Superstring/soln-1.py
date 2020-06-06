class Solution:
    def shortestSuperstring(self, A: List[str]) -> str:
        n = len(A)
        saved = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                if i == j:
                    saved[i][j] = len(A[i])
                    continue
                wi, wj = A[i], A[j]
                for k in range(min(len(wi), len(wj)), 0, -1):
                    if wi[-k:] == wj[:k]:
                        saved[i][j] = k
                        break
        m = (1 << n)
        dp = [[''] * n for _ in range(m)]
        for state in range(m):
            for j in range(n):
                if state & (1 << j) == 0:
                    continue
                if state == (1 << j):
                    dp[state][j] = A[j]
                else:
                    for k in range(n):
                        if k == j:
                            continue
                        if state & (1 << k):
                            temp = dp[state ^ (1 << k)][j]
                            temp += A[k][saved[j][k]:]
                            if dp[state][k] == "" or len(dp[state][k]) > len(temp):
                                dp[state][k] = temp
        mx = math.inf
        ans = None
        for j in range(n):
            if len(dp[m - 1][j]) < mx:
                mx = len(dp[m - 1][j])
                ans = dp[m - 1][j]
        return ans
