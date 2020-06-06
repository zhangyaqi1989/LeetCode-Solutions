class Solution:
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        for key, group in itertools.groupby(nums):
            if key == 1:
                ans = max(ans, len(list(group)))
        return ans