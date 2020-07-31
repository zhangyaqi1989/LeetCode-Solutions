class Solution:
    def isArmstrong(self, N: int) -> bool:
        ans = 0
        k = len(str(N))
        memo_N = N
        while N:
            ans += (N % 10)**k;
            N //= 10
        return ans == memo_N
