class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        zero, two = 0, n - 1
        i = 0
        while i <= two:
            if nums[i] == 0:
                nums[zero] = 0
                zero += 1
            elif nums[i] == 2:
                while i <= two and nums[two] == 2:
                    two -= 1
                if i <= two:
                    if nums[two] == 0:
                        nums[zero] = 0
                        zero += 1
                    nums[two] = 2
                    two -= 1
            i += 1
        for i in range(zero, two + 1):
            nums[i] = 1
