class NumArray:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.sums = list(itertools.accumulate(nums))

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sums[j] if i == 0 else (self.sums[j] - self.sums[i - 1])
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)