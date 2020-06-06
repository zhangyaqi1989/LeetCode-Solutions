class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cur, ans = nums[0], nums[0]
        for num in nums[1:]:
            if cur < 0:
                cur = 0
            cur += num
            if cur > ans:
                ans = cur
        return ans