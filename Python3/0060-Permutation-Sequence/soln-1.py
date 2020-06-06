class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        ans = ''
        digits = list(range(1, n + 1))
        k -= 1
        units = math.factorial(n - 1)
        while n > 0:
            n -= 1
            idx, k = divmod(k, units)
            if n > 0:
                units //= n
            ans += str(digits[idx])
            del digits[idx]
        return ans