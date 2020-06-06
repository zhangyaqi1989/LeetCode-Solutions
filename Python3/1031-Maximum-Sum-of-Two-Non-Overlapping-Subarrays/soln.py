class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        if L < M:
            L, M = M, L
        accs = [0]
        acc = 0
        for num in A:
            acc += num
            accs.append(acc)
        n = len(accs)
        ans = accs[L] + accs[-1] - accs[-M-1]
        for i in range(L, n):
            lacc = accs[i] - accs[i - L]
            macc = -math.inf
            for j in range(i - L + 1):
                if j >= M:
                    macc = max(macc, accs[j] - accs[j - M])
            for j in range(i, n):
                if j + M < n:
                    macc = max(macc, accs[j + M] - accs[j])
            ans = max(ans, lacc + macc)
        return ans
