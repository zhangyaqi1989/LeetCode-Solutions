class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        if K % 2 == 0 or K % 5 == 0:
            return -1
        # 1111111111 divisible by K
        rem, power, ans = 1, 1, 1
        while rem % K != 0:
            ans += 1
            power = power * 10 % K
            rem = (rem + power) % K
        return ans
