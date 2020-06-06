class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        if K % 2 == 0 or K % 5 == 0:
            return -1
        ans = num = 1
        while num % K != 0:
            num = (num * 10 + 1) % K
            ans += 1
        return ans
