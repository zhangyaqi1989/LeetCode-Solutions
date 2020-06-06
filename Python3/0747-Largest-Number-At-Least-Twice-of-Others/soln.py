class Solution:
    def dominantIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # find the largest and second
        first, second, idx = float('-inf'), float('-inf'), 0
        for i, num in enumerate(nums):
            if num > first:
                idx = i
                first, second = num, first
            elif num != first and num > second:
                second = num
        return idx if first == second or first >= second * 2 else -1