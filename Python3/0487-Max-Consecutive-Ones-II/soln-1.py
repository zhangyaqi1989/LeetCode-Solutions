class Solution:
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # use sliding window [l, h]
        max_zeros = 1
        ans = 0
        zeros = 0
        l = 0
        for h, num in enumerate(nums):
            if num == 0:
                zeros += 1
            while zeros > max_zeros:
                zeros -= nums[l] == 0
                l += 1
            ans = max(ans, h - l + 1)
        return ans