class Solution:
    def minDifference(self, nums: List[int]) -> int:
        # pick three values
        if len(nums) <= 4:
            return 0
        nums.sort()
        ans = nums[-1] - nums[0]
        for i in range(4):
            ans = min(nums[-1 - (3 - i)] - nums[i], ans)
        return ans
