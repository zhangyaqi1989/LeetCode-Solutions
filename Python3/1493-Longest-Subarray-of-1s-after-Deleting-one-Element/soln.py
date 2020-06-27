class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        window = collections.Counter()
        lo = 0
        ans = 0
        for i, val in enumerate(nums):
            window[val] += 1
            while window[0] > 1:
                window[nums[lo]] -= 1
                lo += 1
            ans = max(ans, i - lo)
        return ans
