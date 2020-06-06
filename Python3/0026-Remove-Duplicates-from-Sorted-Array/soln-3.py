class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        idx = 0
        for i, num in enumerate(nums):
            if i == 0 or nums[i - 1] != num:
                nums[idx] = num
                idx += 1
        return idx
