class Solution:
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        memo = {}
        def count(start, end):
            if (start, end) in memo:
                return memo[start, end]
            if start >= end:
                memo[start, end] = 0
                return 0
            memo[start, end] = min(guess + max(count(start, guess - 1), count(guess + 1, end)) for guess in range(start, end + 1))
            return memo[start, end]
        return count(1, n)