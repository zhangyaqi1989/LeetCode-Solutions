class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = {0: 1, 1: 1, 2: 2}
        # 3: f(0) * f(2) + f(1) * f(1) + f(2) * f(0)
        # f(n) = f(0) * f(n - 1) + ... + f(n - 1) * f(0) 
        def helper(n):
            if n in dp:
                return dp[n]
            ans = 0
            for i in range(0, n):
                ans += helper(i) * helper(n - 1 - i)
            dp[n] = ans
            return ans
        return helper(n)