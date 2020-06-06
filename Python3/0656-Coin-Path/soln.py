class Solution:
    def cheapestJump(self, A: List[int], B: int) -> List[int]:
        if not A or A[-1] == -1:
            return []
        n = len(A)
        dp = [math.inf] * n
        sucs = [-1] * n
        dp[-1] = A[-1]
        for i in range(n - 2, -1, -1):
            if A[i] == -1:
                continue
            for j in range(i + 1, min(i + B + 1, n)):
                if dp[j] + A[i] < dp[i]:
                    dp[i] = dp[j] + A[i]
                    sucs[i] = j
        if dp[0] == math.inf:
            return []
        path = []
        k = 0
        while k != -1:
            path.append(k + 1)
            k = sucs[k]
        return path
