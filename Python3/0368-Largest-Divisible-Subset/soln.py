class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []
        n = len(nums)
        nums = sorted(nums)
        dp = [[num] for num in nums]
        for i in range(1, n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    if len(dp[j]) + 1 > len(dp[i]):
                        dp[i] = list(dp[j]) + [nums[i]]
        return max(dp, key=len)
