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
        return [[nums[(i*c + j) // n][(i*c + j) % n] for j in range(c)] for i in range(r)]