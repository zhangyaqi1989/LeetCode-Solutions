class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        zeros = 0
        lo = 0
        ans = 0
        for i, val in enumerate(nums):
            zeros += val == 0
            while zeros > 1:
                zeros -= nums[lo] == 0
                lo += 1
            ans = max(ans, i - lo)
        return ans
