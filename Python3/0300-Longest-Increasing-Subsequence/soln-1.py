class Solution:
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return 0
        dp = [1] * len(nums)
        for i, num in enumerate(nums):
            for j in range(i):
                if num > nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)