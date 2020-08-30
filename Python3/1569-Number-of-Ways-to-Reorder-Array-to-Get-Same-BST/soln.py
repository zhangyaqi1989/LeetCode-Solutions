class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        # there are n - 1 slots, find nlefts in it 
        MOD = 1000000007
        def helper(n, k):
            ans = 1
            for i in range(n, n - k, -1):
                ans = ans * i
            for i in range(1, k + 1):
                ans //= i
            return ans % MOD
        def dp(nums):
            if not nums:
                return 1
            root_val = nums[0]
            n = len(nums)
            lefts = [nums[i] for i in range(1, n) if nums[i] < root_val]
            rights = [nums[i] for i in range(1, n) if nums[i] > root_val]
            if (not len(lefts)) and (not len(rights)):
                return 1
            else:
                return dp(lefts) * dp(rights) * helper(n - 1, len(lefts)) % MOD
        return dp(nums) - 1
