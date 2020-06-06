class Solution:
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return max(itertools.chain((len(list(g)) for num, g in itertools.groupby(nums) if num == 1), [0]))