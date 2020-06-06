class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = len(nums) - 2
        while k >= 0:
            if nums[k] < nums[k + 1]:
                break
            k -= 1
        if k < 0:
            nums.reverse()
        else:
            l = n - 1
            while l > k:
                if nums[l] > nums[k]:
                    break
                l -= 1
            nums[k], nums[l] = nums[l], nums[k]
            nums[k + 1:] = nums[k + 1:][::-1]
