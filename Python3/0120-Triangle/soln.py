class Solution:
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if not triangle: return 0
        n = len(triangle)
        dp = [0] * n
        dp[0] = triangle[0][0]
        for i in range(1, n):
            temp = dp[:i]
            dp[0] = temp[0] + triangle[i][0]
            dp[i] = temp[i - 1] + triangle[i][i]
            for j in range(1, i):
                dp[j] = min(temp[j - 1], temp[j]) + triangle[i][j]
        return min(dp)