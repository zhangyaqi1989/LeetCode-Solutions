class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        # such that the sum of the minimum and maximum element on it is less or equal than target
        nums.sort()
        ans = 0
        n = len(nums)
        hi = n - 1
        MOD = 1000000007
        for i in range(n):
            mn = nums[i] # use it
            while hi >= i and mn + nums[hi] > target:
                hi -= 1
            if hi < i:
                break
            length = hi - i
            ans = (ans + pow(2, length, MOD)) % MOD
        return ans
