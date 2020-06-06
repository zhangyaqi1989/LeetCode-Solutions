class Solution:
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        m, n = len(nums), len(nums[0])
        if m * n != r * c:
            return nums
        return list(zip(*[iter(itertools.chain.from_iterable(nums))] * c))