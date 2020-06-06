# this answer is not correct
class Solution:
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        s = sum(nums)
        half, rem = divmod(s, 2)
        if rem: return False
        nums.sort()
        dp = {0:True}
        def helper(nums, idx, target):
            if target in dp:
                return dp[target]
            dp[target] = False
            for i in range(idx, len(nums)):
                if nums[idx] > target:
                    break
                if helper(nums, i + 1, target - nums[i]):
                    dp[target] = True
                    break
            return dp[target]
        return helper(nums, 0, half)
