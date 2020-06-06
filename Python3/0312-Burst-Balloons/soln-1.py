class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + [num for num in nums if num] + [1]
        n = len(nums)
        dp = [[0] * n for _ in range(n)]
        for length in range(1, n - 1):
            for l in range(0, n - 1 - length):
                r = l + length + 1
                for m in range(l + 1, r):
                    dp[l][r] = max(dp[l][r], dp[l][m] + nums[l] * nums[m] * nums[r] + dp[m][r])
        return dp[0][-1]
