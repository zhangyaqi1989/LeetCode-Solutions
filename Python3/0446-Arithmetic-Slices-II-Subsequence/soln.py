class Solution:
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        # first two numbers determines the whole
        n = len(A)
        dp = [collections.Counter() for _ in range(n)]
        cnt = 0
        for i in range(1, n):
            for j in range(i):
                delta = A[i] - A[j]
                dp[i][delta] += 1
                if dp[j][delta]:
                    dp[i][delta] += dp[j][delta]
                    cnt += dp[j][delta]
        return cnt
