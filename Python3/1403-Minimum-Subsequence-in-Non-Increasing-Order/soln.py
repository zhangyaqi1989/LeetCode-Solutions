class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        s = sum(nums)
        ans = []
        cur = 0
        for num in sorted(nums, reverse=True):
            cur += num
            ans.append(num)
            if cur > s - cur:
                return ans
        return ans
