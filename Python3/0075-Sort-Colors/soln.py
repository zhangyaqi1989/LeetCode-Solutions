class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # three types
        zero, two = 0, len(nums) - 1
        i = 0
        while i <= two:
            if nums[i] == 2:
                nums[i], nums[two] = nums[two], nums[i]
                two -= 1
            elif nums[i] == 0:
                nums[zero] = 0
                i += 1
                zero += 1
            else:
                i += 1
        nums[zero:two + 1] = [1] * (two - zero + 1) 