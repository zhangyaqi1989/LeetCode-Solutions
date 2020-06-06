class Solution:
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # 3 5 2 1
        for i in range(len(nums) - 1):
            if i % 2:
                if nums[i + 1] > nums[i]:
                    nums[i], nums[i + 1] = nums[i + 1], nums[i]
            else:
                if nums[i + 1] < nums[i]:
                    nums[i], nums[i + 1] = nums[i + 1], nums[i]