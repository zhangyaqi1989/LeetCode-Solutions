class Solution:
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        summation = sum(nums)
        acc = 0
        for idx, num in enumerate(nums):
            if acc * 2 + num == summation:
                return idx
            acc += num
        return -1