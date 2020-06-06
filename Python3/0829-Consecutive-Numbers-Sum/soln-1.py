class Solution:
    def consecutiveNumbersSum(self, N: int) -> int:
        cnt = 0
        for m in range(1, N + 1):
            mx = N - m * (m - 1) // 2
            if mx <= 0:
                break
            if mx % m == 0:
                cnt += 1
        return cnt
