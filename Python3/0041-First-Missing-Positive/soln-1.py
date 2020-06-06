class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # constant space
        # [1, len(nums) + 1]
        n = len(nums)
        for i, num in enumerate(nums):
            if num < 0 or num > n:
                nums[i] = 0
        n += 1
        for i, num in enumerate(nums):
            idx = num % n
            if idx:
                nums[idx - 1] += n
        for i, num in enumerate(nums, 1):
            if num // n == 0:
                return i
        return n