class Solution:
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 2 * 5 = 10
        ans = 0
        while n >= 5:
            ans += n // 5
            n //= 5
        return ans