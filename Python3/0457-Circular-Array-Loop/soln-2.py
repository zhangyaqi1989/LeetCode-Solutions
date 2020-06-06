class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)
        for i, num in enumerate(nums):
            mark = str(i)
            j = i
            while type(nums[j]) == int and num * nums[j] > 0 and nums[j] % n != 0:
                jump = nums[j]
                nums[j] = mark
                j = (j + jump) % n
            if nums[j] == mark:
                return True
        return False
