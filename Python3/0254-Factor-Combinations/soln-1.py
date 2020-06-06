ass Solution:
    def getFactors(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        ans = []
        def helper(n, i, factors):
            while i * i <= n:
                if n % i == 0:
                    ans.append(factors + [i, n // i])
                    helper(n // i, i, factors + [i])
                i += 1
        helper(n, 2, [])
        return ans
