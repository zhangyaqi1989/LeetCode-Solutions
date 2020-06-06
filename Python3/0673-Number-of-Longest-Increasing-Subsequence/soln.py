class Solution:
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        n = len(nums)
        dp = [[1, 1] for _ in range(n)]
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    if dp[i][0] == dp[j][0] + 1:
                        dp[i][1] += dp[j][1]
                    elif dp[i][0] < dp[j][0] + 1:
                        dp[i][0] = dp[j][0] + 1
                        dp[i][1] = dp[j][1]
        mx_len = max(length for length, _ in dp)
        return sum(cnt for length, cnt in dp if length == mx_len)
