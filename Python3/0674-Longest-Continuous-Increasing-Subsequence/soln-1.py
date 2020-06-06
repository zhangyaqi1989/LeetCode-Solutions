class Solution:
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        ans = 1
        cur = 1
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                cur += 1
                ans = max(cur, ans)
            else:
                cur = 1
        return ans
