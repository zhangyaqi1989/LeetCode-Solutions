class Solution:
    def concatenatedBinary(self, n: int) -> int:
        ans = 0
        MOD = 1000000007
        for num in range(1, n + 1):
            bnum = bin(num)[2:]
            m = len(bnum)
            ans = ((ans << (m)) + num) % MOD
        return ans
