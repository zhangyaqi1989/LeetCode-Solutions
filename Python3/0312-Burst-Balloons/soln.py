class Solution:
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = [1] + nums + [1]
        n = len(nums)
        dp = [[0] * n for _ in range(n)]
        def helper(i, j):
            if dp[i][j] or j == i + 1:
                return dp[i][j]
            coins = 0
            for k in range(i + 1, j):
                coins = max(coins, nums[i] * nums[k] * nums[j] + helper(i, k) + helper(k, j))
            dp[i][j] = coins
            return coins
        return helper(0, n - 1)